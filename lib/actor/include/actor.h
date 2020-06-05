//
// Created by darkwayc0de on 28/5/20.
//

#ifndef ACTOR_H
#define ACTOR_H

#include <algorithm>
#include <optional>
#include <stack>
#include <string>
#include <thread>
#include <vector>

#include "mailbox.h"

class Actor {
protected:
	Actor* m_parent;
	std::stack<std::string> m_mail;
	std::vector<Actor*> m_children;

	void remove_child(Actor* child);

public:
	Actor(Actor* parent = nullptr);
	virtual ~Actor();

	void send(Actor* dest, std::string message);
	std::optional<std::string> sender();

	void kill();

};


#endif // ACTOR_H
