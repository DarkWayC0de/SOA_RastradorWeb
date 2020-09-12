//
// Created by darkwayc0de on 28/5/20.
//
#ifndef SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_MANAGER_H
#define SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_MANAGER_H

#include <memory>
#include <actors_global.h>


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

private:
    static ActorManager* instance_;
    ActorManager();

};

template<typename ActorClass>
ActorClass *ActorManager::spawn(Actor *parent) {
    static_assert(std::is_base_of<Actor,ActorClass>::value);
    return new ActorClass(parent == nullptr ? root_actor_.get() : parent);
}

#endif //SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_MANAGER_H
