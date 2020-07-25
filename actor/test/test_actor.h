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
		std::optional<Mail> opt_mail = get_mail();

		if (opt_mail.has_value()) {
			try {
				return process_mail(*opt_mail);
			} catch (std::exception& e) {
				send(Mail((*opt_mail).first, "failed"));
			}
		}

		return "";
	}

	std::string process_mail(Mail& mail) {
		if (mail.second == "hello") {
			return "world";
		}
		return getUnknown(mail);
	}

	std::string getUnknown(Mail& mail) {
		if (mail.second == "unknown") {
			return "unknown";
		} if (mail.second == "throw") {
			throw TestException();
		}
		return "";
	}

	void set_kill_flag(bool* flag) {
		m_kill = flag;
	}

};


#endif // TESTACTOR_H
