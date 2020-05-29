#include "gtest/gtest.h"
#include "../include/actor/ActoManager.h"
#include "TestActor.h"

TEST(ActorManager, TestSend) {
	// Crear supervisor
///	ActorManager manager;
	// Crear test actor
///	TestActor actor(manager);
///	// Supervisor envia "hello" al test actor
///	manager.send(actor, "hello");
///	ASSERT_EQ(actor.sender(), "hello");
}

TEST(ActorManager, TestSpawn) {
	// Crear supervisor
	ActorManager manager;
	// Crear test actor padre
///	TestActor parent(manager);
///	// Supervisor crea test actor hijo del padre
///	TestActor child = manager.spawn(parent);
///	ASSERT_EQ(parent.children.back(), child);
}

TEST(ActorManager, TestKill) {
	// Crear supervisor
	ActorManager manager;
	// Crear test actor
///	TestActor actor(manager);
	// Supervisor envia señal kill al test actor
///	manager.kill(actor);
///	ASSERT_EQ(actor, nullptr);
}
