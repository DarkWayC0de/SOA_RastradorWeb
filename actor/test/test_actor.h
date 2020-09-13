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
public:
    int getIntProperty() const {
        return int_property;
    }

    void setIntProperty(int intProperty) {
        int_property = intProperty;
    }

private:

    void h_update_int(int arg) {
        int_property = arg;
    }

public:
    template <typename... Types>
    bool test_sender(Actor* receiver , const std::string& message,Types&&... args) {
        return send(receiver,message,std::forward<Types>(args)...) ;
    }

protected:
    TestActor(Actor* parent) : Actor(parent) {
        std::function<void(TestActor&, int)> fn = &TestActor::h_update_int;
        create_handler("update_int", fn);
    }

};


#endif // TESTACTOR_H
