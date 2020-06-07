//
// Created by darkwayc0de on 28/5/20.
//

#include "actor.h"

Actor::Actor(Actor* parent)/*:Qobjet(parent)*/{

}

bool Actor::delivery_from(Actor* sender /*, const Message& message*/ ){
    //TODO: entregar mensaje al mailbox
}

bool Actor::send( Actor* receiver /*, const Message& message*/ ){
    return receiver->delivery_from(this/*,message*/);
}

bool Actor::reply(/*, const Message& message*/){
    if(lastSender_){
        return send(lastsender/*, message*/);
    }
    return false;
}