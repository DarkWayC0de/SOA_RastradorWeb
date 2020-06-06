//
// Created by darkwayc0de on 28/5/20.
//

#ifndef ACTOR_H
#define ACTOR_H

#include <algorithm>
#include <optional>
#include <queue>
#include <string>
#include <thread>
#include <utility>
#include <vector>

class Actor;

typedef std::pair<Actor*, std::string> Mail;
typedef std::queue<Mail> Mailbox;

class Actor {
protected:
	Actor* m_parent;
	Mailbox m_mail;
	std::vector<Actor*> m_children;

	std::optional<Mail> get_mail();
	void remove_child(Actor* child);

public:
	Actor(Actor* parent = nullptr);
	virtual ~Actor();

	void send(Mail mail);
	void send(Actor* dest, std::string message);
	std::optional<std::string> sender();

	void kill();

};


#endif // ACTOR_H
