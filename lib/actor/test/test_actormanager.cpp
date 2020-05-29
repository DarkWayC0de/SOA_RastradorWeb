#include "ActorManager.h"
#include "TestActor.h"
#include "gtest/gtest.h"

TEST(ActorManager, TestSend) {
	// Crear supervisor
	ActorManager manager;
	// Crear test actor
	TestActor actor(manager);
	// Supervisor envia "hello" al test actor
	manager.send(actor, "hello");
	EXPECT_EQ(actor.sender(), "hello");
}

TEST(ActorManager, TestSpawn) {
	// Crear supervisor
	ActorManager manager;
	// Crear test actor padre
	TestActor parent(manager);
	// Supervisor crea test actor hijo del padre
	TestActor child = manager.spawn(parent);
	EXPECT_EQ(parent.children.back(), child);
}

TEST(ActorManager, TestKill) {
	// Crear supervisor
	ActorManager manager;
	// Crear test actor
	TestActor actor(manager);
	// Supervisor envia señal kill al test actor
	manager.kill(actor);
	EXPECT_EQ(actor, nullptr);
}
