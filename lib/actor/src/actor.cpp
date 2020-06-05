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

void Actor::send(Actor* dest, std::string message) {
	dest->m_mail.push(message);
}

std::optional<std::string> Actor::sender() {
	if (!m_mail.empty()) {
		return m_mail.top();
	}
	return {};
}

void Actor::kill() {
	delete this;
}

void Actor::remove_child(Actor* child) {
	m_children.erase(
	  std::remove(m_children.begin(),
		m_children.end(), child),
		m_children.end()
	);
}
