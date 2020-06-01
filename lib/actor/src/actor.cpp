//
// Created by darkwayc0de on 28/5/20.
//

#include "actor.h"

Actor::Actor(Actor* parent) {
	if (parent) {
		m_parent = parent;
		// parent.addChildren(this);
	} else {
		m_parent = nullptr;
	}
}

Actor::~Actor() {

}

void Actor::send(Actor& dest, std::string message) {

}

std::string* Actor::sender() {
	return nullptr;
}

