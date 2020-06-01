//
// Created by darkwayc0de on 27/5/20.
//
#include "gtest/gtest.h"
#include "TestActor.h"

TEST(TestActor, TestSenderNullptr) {
	TestActor a;
	EXPECT_EQ(a.sender(), nullptr);
}

TEST(TestActor, TestSenderRemitente) {
	TestActor a, b;
	a.send(b, "hello");
	EXPECT_EQ(*b.sender(), "bye");
}

/*
TEST(TestActor, TestReply) {
	TestActor a, b;
	a.send(b, "hello");
	EXPECT_EQ(b.getReply(), "world");
}

TEST(TestActor, TestUnknownMessage) {
	TestActor a, b;
	a.send(b, "unknown");
	EXPECT_EQ(b.getUnknown(), "unknown");
	a.send(b, "hello");
	EXPECT_EQ(b.getUnknown(), "unknown");
}

TEST(TestActor, TestKill) {
	TestActor a, b(a);
	a.kill();
	EXPECT_EQ(&a, nullptr);
	EXPECT_EQ(&b, nullptr);
}

TEST(TestActor, TestFailed) {
	// Crear test actor padre e hijo
	TestActor parent, child(parent);

	// padre envía mensaje que el hijo no puede procesar
	parent.send(child, "throw");

	// hijo envía mensaje "failed" a mailbox del padre
	// a través de excepciones manejadas por el hijo
	EXPECT_EQ(parent.getReply(), "failed");
}
*/
