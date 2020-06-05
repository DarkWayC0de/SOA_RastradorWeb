//
// Created by darkwayc0de on 28/5/20.
//

#ifndef TESTACTOR_H
#define TESTACTOR_H

#include "actor.h"

class TestActor : public Actor {
public:
    ~TestActor() = default;

	std::string getReply() {
		return "";
	};

	std::string getUnknown() {
		return "";
	};

};


#endif // TESTACTOR_H
