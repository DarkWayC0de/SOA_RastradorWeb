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
	bool* m_kill;
public:
	TestActor(TestActor* parent = nullptr) : Actor(parent)  { }

	~TestActor() {
		*m_kill = true;
	}

	std::string getReply() {
		try {
			std::string reply = processMessage();
			return reply;
		} catch (std::exception& e) {
			return "failed";
		}
	};

	std::string processMessage() {
		if (m_mail.top() == "hello") {
			return "world";
		}
		return getUnknown();
	}

	std::string getUnknown() {
		if (m_mail.top() == "unknown") {
			return "unknown";
		} if (m_mail.top() == "throw" ) {
			throw TestException();
		}
		return "";
	};

	void set_kill_flag(bool* flag) {
		m_kill = flag;
	}

};


#endif // TESTACTOR_H
