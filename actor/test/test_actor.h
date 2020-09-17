//
// Created by darkwayc0de on 28/5/20.
//

#ifndef TESTACTOR_H
#define TESTACTOR_H

#include <iostream>
#include <exception>
#include <functional>
#include "actor.h"

struct TestException : public std::exception {
	const char* what() const throw() {
		return "Test exception";
	}
};

class TestActor : public Actor {
private:
    int int_property_;
    Actor* sender_;
public:
    Actor *getSender() const {
        return sender_;
    }

    int getIntProperty() const {
        return int_property_;
    }

    TestActor* spawnchildActorAndFail(){
     //TODO spawnchildactorandfail
    }

private:
    void senderiscorrect(){
       sender_ = getLastSender();
    }
    void h_update_int(int arg) {
        std::cout<<"aguita\n";
        int_property_ = arg;
    }
    void replygetIntProperrty(int arg){
        this->reply("update_int",arg);
    }

public:
    template <typename... Types>
    bool test_sender(Actor* receiver, const std::string& message,Types&&... args) {
        return this->send(receiver, message, std::forward<Types>(args)...) ;
    }

    TestActor(Actor* parent) : Actor(parent) {
        std::function<void(int)> fn = [this](int arg) {
            this->h_update_int(arg);
        };
        this->Actor::create_handler("update_int", fn);

        std::function<void()> fn1 = [this]() {
            this->senderiscorrect();
        };
        this->Actor::create_handler("senderiscorrect", fn1);
        std::function<void(int)> fn2 = [this](int a) {
            this->replygetIntProperrty(a);
        };
        this->Actor::create_handler("replygetIntProperrty", fn2);
    }
};


#endif // TESTACTOR_H
