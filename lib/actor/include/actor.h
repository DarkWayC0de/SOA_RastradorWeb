//
// Created by darkwayc0de on 28/5/20.
//

#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <vector>

#include "mailbox.h"


class Actor {
private:
	Actor* m_parent;
	Mailbox m_mail;
	std::vector<Actor*> m_children;

public:
    Actor(Actor* parent = nullptr);
    virtual ~Actor();

    void send(Actor& dest, std::string message);
	std::string* sender();
};


#endif // ACTOR_H
