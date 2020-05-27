//
// Created by darkwayc0de on 27/5/20.
//
#include "gtest/gtest.h"
#include "actor/Actor.h"
#include "test_actor.h"

TEST_F(TestActor, TestSenderNullptr) {
	TestActor a;
	ASSERT_EQ(actor.sender(), nullptr);
}

TEST_F(TestActor, TestSenderRemitente) {
	TestActor a, b;
	a.send(b, "hello");
	ASSERT_EQ(b.sender(), "hello");
}

TEST_F(TestActor, TestReply) {
	TestActor a, b;
	a.send(b, "hello");
	ASSERT_EQ(b.getReply(), "world");
}

TEST_F(TestActor, TestUnknownMessage) {
	TestActor a, b;
	a.send(b, "unknown");
	ASSERT_EQ(b.getUnknown(), "unknown");
	a.send(b, "hello");
	ASSERT_EQ(b.getUnknown(), "unknown");
}

TEST_F(TestActor, TestKill) {
	TestActor a, b(a);
	a.kill();
	ASSERT_EQ(a, nullptr);
	ASSERT_EQ(b, nullptr);
}

TEST_F(TestActor, TestFailed) {
	// Crear test actor padre e hijo
	TestActor parent, child(parent);

	// padre envía mensaje que el hijo no puede procesar
	parent.send(child, "throw");

	// hijo envía mensaje "failed" a mailbox del padre
	// a través de excepciones manejadas por el hijo
	ASSERT_EQ(parent.getReply(), "failed");
}
