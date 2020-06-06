//
// Created by darkwayc0de on 28/5/20.
//

#include "actor.h"

Actor::Actor(Actor* parent) {
	if (parent) {
		m_parent = parent;
		m_parent->m_children.push_back(this);
	}
}

Actor::~Actor() {
	if (m_parent) {
		m_parent->remove_child(this);
	}

	for (Actor*& child : m_children) {
		child->kill();
	}
}

void Actor::send(Mail mail) {
	mail.first->m_mail.push(Mail(this, mail.second));
}

void Actor::send(Actor* dest, std::string message) {
	send(Mail(dest, message));
}

std::optional<std::string> Actor::sender() {
	if (!m_mail.empty()) {
		Mail mail = m_mail.front();
		return std::make_optional<std::string>(mail.second);
	}
	return {};
}

void Actor::kill() {
	delete this;
}

std::optional<Mail> Actor::get_mail() {
	if (!m_mail.empty()) {
		Mail mail = m_mail.front();
		m_mail.pop();
		return std::make_optional<Mail>(mail);
	}
	return {};
}

void Actor::remove_child(Actor* child) {
	m_children.erase(
	  std::remove(m_children.begin(),
		m_children.end(), child),
		m_children.end()
	);
}
