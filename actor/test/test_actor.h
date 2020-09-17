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
		return "Test failure";
	}
};

class TestActor : public Actor {
private:
    int int_property_;
    Actor* sender_;
    bool unknown_;
    bool child_failure_;
public:
    Actor *getSender() const {
        return sender_;
    }

    int getIntProperty() const {
        return int_property_;
    }

    TestActor* spawnchildActorAndFail(){
        auto ret = new TestActor(this);
        try {
            ret->fail();
        } catch (TestException& e) {
            std::cout << e.what() << '\n';
        }
        return ret;
    }

    void fail() {
        this->test_sender(parent_, "failure", true);
        throw TestException();
    }

private:
    void senderiscorrect(){
       sender_ = getLastSender();
    }
    void h_update_int(int arg) {
        int_property_ = arg;
    }
    void replygetIntProperrty(int arg){
        this->reply("update_int",arg);
    }

    void updateUnknownState() {
        this->unknown_ = true;
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

        std::function<void()> kill_ftor = [this] () -> void {
            this->kill();
        };
        this->Actor::create_handler("kill", kill_ftor);

        std::function<void(bool)> child_failure_ftor = [this] (bool failure) -> void {
            child_failure_ = failure;
        };
        this->Actor::create_handler("failure", child_failure_ftor);

        unknown_msg_handler_ = new Delegate(std::function<void()>([this] () -> void {
              this->updateUnknownState();
        }));
    }
    
    bool getChildFailure() {
        return child_failure_;
    }

    bool getUnknownProperty() {
        return unknown_;
    }
};


#endif // TESTACTOR_H
