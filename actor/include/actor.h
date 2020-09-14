//
// Created by darkwayc0de on 28/5/20.
//

#ifndef SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
#define SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H

#include <functional>
#include <thread>
#include <pthread.h>
#include <actors_global.h>

#include "Mailbox.h"
#include "Delegate.h"

class Actor;

class EXPORTED ActorManager  {
private:
    std::unique_ptr<Actor>  root_actor_;
public:
    static  ActorManager* instance();

    template<typename ActorClass>
    ActorClass* spawn(Actor* parent = nullptr);

    void kill(Actor* actor);

    ~ActorManager();

    template <typename... Types>
    bool send( Actor* receiver , const std::string& message,Types&&... args);


    static ActorManager* instance_;
private:
    ActorManager();

};

template<typename ActorClass>
ActorClass *ActorManager::spawn(Actor *parent) {
    static_assert(std::is_base_of<Actor,ActorClass>::value);
    return new ActorClass(parent == nullptr ? root_actor_.get() : parent);
}

class EXPORTED Actor {
private:
    using Message = std::function<void()>;// TODO falta "tipar" el argumento
    Mailbox<Message> mailbox_;
    std::thread thread_;
    Actor* parent_;
    Actor* lastSender_ = nullptr;
    std::unordered_map<std::string, Delegate> handlers_;

public:
    ~Actor();

    template<typename... Types>
    bool deliver_from(Actor* sender, const std::string& message, Types&&... args);
    void deletelater();


protected:
    explicit Actor(Actor* parent);

    template <typename... Types>
    bool send( Actor* receiver , const std::string& message,Types&&... args);

    template<typename... Types>
    bool reply(const Message& message,Types&&... arg);

    template<typename ActorClass>
    ActorClass* spawn();

    template<typename... Types>
    void create_handler(const std::string& message, std::function<void (Types...)> fn);

private:
    template<typename... Types>
    void invoke_handler(const std::string& message, Types&&... args);

    void processMessage();
    friend ActorManager;
};

template<typename ActorClass>
ActorClass *Actor::spawn() {
    return ActorManager::instance()->spawn<ActorClass>(this);
}

ActorManager* ActorManager::instance_ = nullptr;



template<typename... Types>
bool ActorManager::send(Actor *receiver, const std::string &message, Types &&... args) {
    return receiver -> deliver_from(nullptr, message, std::forward<Types>(args)...);
}


template<typename... Types>
bool Actor::reply(const Message& message,Types&&... args){
    if(lastSender_){
        return send(lastSender_ , message, std::forward<Types>(args)...);
    }
    return false;
}



template<typename... Types>
bool Actor::send(Actor* receiver, const std::string& message, Types&&... args) {
    return receiver->deliver_from(this, message, std::forward<Types>(args)...);
}

template<typename... Types>
bool Actor::deliver_from(Actor *sender, const std::string &message, Types&&... args) {
    // mailbox_.push(std::bind(invoke_handler<Types...>, message, args...));
    mailbox_.push([this, message, args...]() {
        this->invoke_handler(message, args...);
    });
    return true;
}

template<typename... Types>
void Actor::invoke_handler(const std::string &message, Types &&... args) {
    if (handlers_.count(message)){
        auto delegate = handlers_.at(message);
        delegate(std::forward<Types>(args)...);
    } else {
        // TODO: No exite el evento.
        // TODO: Durante el desarrollo sería buena idea indicarlo con una
        // TODO: advertencia en la consola.
    }
}


template<typename... Types>
void Actor::create_handler(const std::string &message, std::function<void(Types...)> fn) {
    handlers_.emplace(message, fn);
}

ActorManager* ActorManager::instance() {
    if (!instance_)
        instance_ = new ActorManager();

    return instance_;
}

Actor::Actor(Actor* parent):
        thread_(&Actor::processMessage, this),
        parent_(parent){
}

Actor::~Actor() {
    deletelater();
}

void Actor::deletelater() {}


void Actor::processMessage() {}

ActorManager::ActorManager(): root_actor_(new Actor(nullptr)){}

void ActorManager::kill(Actor* actor) {

}

ActorManager::~ActorManager() {
    root_actor_ -> deletelater();
}
#endif //SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
