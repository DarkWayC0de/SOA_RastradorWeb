//
// Created by darkwayc0de on 28/5/20.
//

#ifndef SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
#define SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H

#include <functional>
#include <thread>
#include <pthread.h>
#include <actors_global.h>
#include <ActorManager.h>

#include "Mailbox.h"
#include "Delegate.h"


class EXPORTED Actor {
private:
    using Message = std::function<void()>;// TODO  falta el tipo dentro parantesis void
    Mailbox<Message> mailbox_;
    std::thread thread_;
    Actor* parent_;
    Actor* lastSender_ = nullptr;
    std::unordered_map<std::string, Delegate> handlers_;

public:
    ~Actor();

    template<typename... Types>
    bool deliver_from(Actor* sender, const std::string& message, Types&&... args);
    void deletelater(void);


protected:
    template <typename... Types>
    bool send( Actor* receiver , const std::string& message,Types&&... args);
    template<typename... Types>
    bool reply(const Message& message,Types&&... arg);
    Actor* spawn();

private:
    explicit Actor(Actor* parent);
    template<typename... Types>
    void invoke_handler(const std::string& message, Types&&... args);
    template<typename... Types>
    void handle(const std::string& message, std::function<void (Types...)> fn);
    void processMessage();
    friend ActorManager;
};



#endif //SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
