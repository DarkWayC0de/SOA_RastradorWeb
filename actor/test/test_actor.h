//
// Created by darkwayc0de on 28/5/20.
//

#ifndef TESTACTOR_H
#define TESTACTOR_H

#include <exception>
#include "actor.h"

struct TestException : public std::exception {
	const char* what() const throw() {
		return "Test exception";
	}
};

class TestActor : public Actor {
private:
    int int_property;

    void h_update_int(int arg) {
        int_property = arg;
    }

public:
    TestActor(Actor* parent) : Actor(parent) {
        std::function<void(TestActor&, int)> fn = &TestActor::h_update_int;
        create_handler("update_int", fn);
    }

    void* test_sender() {
        // return sender();
        return nullptr;
    }

};


#endif // TESTACTOR_H
