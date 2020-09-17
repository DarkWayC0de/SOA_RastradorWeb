//
// Created by darkwayc0de on 28/5/20.
//

#ifndef SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
#define SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H

#include <functional>
#include <thread>
#include <pthread.h>
#include <actors_global.h>
#include <atomic>

#include "Mailbox.h"
#include "Delegate.h"

class Actor;

//////////////////
// ACTORMANAGER //
//////////////////

class EXPORTED ActorManager {
private:
    std::unique_ptr<Actor>  root_actor_;
    ActorManager();

public:
    static ActorManager* instance_;
    static ActorManager* instance() {
        if (!instance_) {
            instance_ = new ActorManager();
        }

        return instance_;
    }

    template<typename ActorClass>
    static ActorClass* spawn(Actor* parent = nullptr);
    static void kill(Actor* actor);
    static bool threadlive(Actor* actor);

    ~ActorManager() {
        kill(root_actor_.get());
    }

    template<typename... Types>
    static bool send(Actor* receiver , const std::string& message,Types&&... args);

};

template<typename ActorClass>
ActorClass *ActorManager::spawn(Actor *parent) {
    static_assert(std::is_base_of<Actor,ActorClass>::value);
    return new ActorClass(parent == nullptr ? instance_->root_actor_.get() : parent);
}

///////////
// ACTOR //
///////////

class EXPORTED Actor {
private:
    using Message = std::function<void()>;
    Mailbox<Message> mailbox_;
    Actor* lastSender_ = nullptr;

    std::thread thread_;
    std::unordered_map<std::string, Delegate> handlers_;

    std::atomic_bool done_;

    template<typename... Types>
    void invoke_handler(const std::string& message, Types&&... args);

    bool processMessage() {
        auto message = mailbox_.pop(std::chrono::milliseconds(100));
        if(message){
           std::invoke(message.value());
        }
        return !done_;
    }

    template<typename... Types>
    void unknownMessage(const std::string& message, Types&&... args) {
        // if there is a function to handle unknown messages { launch function }
        if (unknown_msg_handler_) {
            (*unknown_msg_handler_)();
        }
    }

    void thread() {
        while(this->processMessage());
        this->deletelater();
    }

    friend ActorManager;

protected:
    explicit Actor(Actor* parent) :
        thread_(&Actor::thread, this),
        parent_(parent),
        done_(false) {
        std::function<void()> fn = [this]() {
            this->kill();
        };
        this->Actor::create_handler("kill", fn);
    }

    template <typename... Types>
    bool send(Actor* receiver, const std::string& message,Types&&... args);

    template<typename... Types>
    bool reply(const std::string& message,Types&&... arg);

    template<typename ActorClass>
    ActorClass* spawn();

    template<typename... Types>
    void create_handler(const std::string& message, std::function<void (Types...)> fn);

    template<typename... Types>
    bool deliver_from(Actor* sender, const std::string& message, Types&&... args);

    Actor* getLastSender() const {
        return lastSender_;
    }

    void kill() {
        this->done_ =true;
    }

    virtual void deletelater(){} // TODO le

    Actor* parent_;
    Delegate* unknown_msg_handler_;

public:
    ~Actor() {
        delete unknown_msg_handler_;
        if(!thread_.joinable()) {
           std::cerr << "Attempted to remove an Actor without using kill before";
        }
    }

};

template<typename ActorClass>
ActorClass* Actor::spawn() {
    return ActorManager::instance()->spawn<ActorClass>(this);
}


template<typename... Types>
bool Actor::reply(const std::string& message,Types&&... args){

    if(lastSender_) {
        return send(lastSender_ , message, std::forward<Types&&>(args)...);
    }
    return false;
}

template<typename... Types>
bool Actor::send(Actor* receiver, const std::string& message, Types&&... args) {
    return receiver->deliver_from(this, message, std::forward<Types&&>(args)...);
}

template<typename... Types>
bool Actor::deliver_from(Actor *sender, const std::string &message, Types&&... args) {
    lastSender_ = sender;
    mailbox_.push([this, message, ...args = std::forward<Types&&>(args)] {
        this->invoke_handler(message, std::forward<decltype(args)>(args)...);
    });
    return true;
}

template<typename... Types>
void Actor::invoke_handler(const std::string &message, Types&&... args) {
    if (handlers_.count(message)) {
        auto delegate = handlers_.at(message);
        delegate(std::forward<Types&&>(args)...);
    } else {
        // Mensaje desconocido
        unknownMessage(message, std::forward<Types&&>(args)...);
    }
}

template<typename... Types>
void Actor::create_handler(const std::string &message, std::function<void(Types...)> fn) {
    handlers_.emplace(message, fn);
}


/*
 * Métodos de ActorManager dependientes de Actor implementado
 */

template<typename... Types>
bool ActorManager::send(Actor *receiver, const std::string &message, Types&&... args) {
    return receiver->deliver_from(nullptr, message, std::forward<Types&&>(args)...);
}

#endif //SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
