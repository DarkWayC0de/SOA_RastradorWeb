//
// Created by darkwayc0de on 28/5/20.
//

#include <actor.h>
#include <ActorManager.h>

Actor::Actor(Actor* parent):
                        thread_(&Actor::processMessage, this),
                        parent_(parent){

}
template<typename... Types>
bool Actor::reply(const Message& message,Types&&... args){
    if(lastSender_){
        return send(lastSender_ , message, std::forward<Types>(args)...);
    }
    return false;
}

void Actor::processMessage() {}

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

void Actor::deletelater() {}

template<typename... Types>
void Actor::create_handler(const std::string &message, std::function<void(Types...)> fn) {
    handlers_.emplace(message, fn);
}

Actor::~Actor() {
   deletelater();
}




