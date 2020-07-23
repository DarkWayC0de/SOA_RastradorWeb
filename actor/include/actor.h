//
// Created by darkwayc0de on 28/5/20.
//

#ifndef SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
#define SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H

#include <functional>
#include <thread>
#include <pthread.h>
#include "actors_global.h"
#include "Mailbox.h"
#include "Delegate.h"
//class ActorThead; //TODO SOBRA?

class EXPORTED Actor {
private:
    using Message = std::function<void(T)>;
    Mailbox<Message> mailbox_;
    std::thread thread_;
    Actor* lastSender_ = nullptr;
    std::unordered_map<std::string, Delegate> handlers_;

public:
    virtual ~Actor();
    explicit Actor(Actor* parent);
    template<typename... Types>
    bool deliver_from(Actor* sender, const std::string& message, Types&&... args);


protected:
    template <typename... Types>
    bool send( Actor* receiver , const std::string& message,Types&&... args);
    template<typename... Types>
    bool reply(const Message& message,Types&&... arg);

private:
    template<typename... Types>
    void invoke_handler(const std::string& message, Types&&... args);
    template<typename... Types>
    void handle(const std::string& message, std::function<void (Types...)> fn);
    void processMessage();
    // friend ActorThead; TODO no hace falta?
};



#endif //SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
