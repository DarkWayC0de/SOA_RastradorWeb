//
// Created by darkwayc0de on 28/5/20.
//

#ifndef SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
#define SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H

#include "actors_global.h"
#include "Mailbox.h"


class EXPORTED Actor /*hereda de Qobjetc*/ {
private:
//    Mailbox<Message> mailbox_;
//    Qthread thread_;
    Actor* lastSender_ = nullptr;


public:
    virtual ~Actor() = default;
    explicit Actor(Actor* parent);
    bool delivery_from(Actor * sender /*, const Message& message*/ );

protected:
    bool send( Actor* receiver /*, const Message& message*/ );
    bool reply(/*, const Message& message*/);
};


#endif //SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
