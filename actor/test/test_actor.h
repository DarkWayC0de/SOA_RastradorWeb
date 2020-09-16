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
public:

    int getIntProperty() const {
        return int_property_;
    }
    TestActor* spawnchildActorAndFail(){
     //TODO spawnchildactorandfail
    }

private:

    void h_update_int(int arg) {
        int_property_ = arg;
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
    }

    };


#endif // TESTACTOR_H
