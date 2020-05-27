#include "gtest/gtest.h"
#include "actor/Actor.h"
#include "actor/ActorManager.h"
#include "test_actor.h"

TEST_F(ActorManager, TestSend) {
	// Crear supervisor
	ActorManager manager;
	// Crear test actor
	TestActor actor(manager);
	// Supervisor envia "hello" al test actor
	manager.send(actor, "hello");
	ASSERT_EQ(actor.sender(), "hello");
}

TEST_F(ActorManager, TestSpawn) {
	// Crear supervisor
	ActorManager manager;
	// Crear test actor padre
	TestActor parent(manager);
	// Supervisor crea test actor hijo del padre
	TestActor child = manager.spawn(parent);
	ASSERT_EQ(parent.children.back(), child);
}

TEST_F(ActorManager, TestKill) {
	// Crear supervisor
	ActorManager manager;
	// Crear test actor
	TestActor actor(manager);
	// Supervisor envia señal kill al test actor
	manager.kill(actor);
	ASSERT_EQ(actor, nullptr);
}
