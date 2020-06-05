//
// Created by darkwayc0de on 27/5/20.
//

#include <memory>
#include "gtest/gtest.h"
#include "test_actor.h"

TEST(TestActor, TestSenderNullptr) {
	TestActor* a = new TestActor();
	EXPECT_EQ(a->sender().has_value(), false);
}

TEST(TestActor, TestSenderRemitente) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor();
	a->send(b, "hello");
	EXPECT_EQ(b->sender(), "hello");
}

TEST(TestActor, TestReply) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor();
	a->send(b, "hello");
	EXPECT_EQ(b->getReply(), "world");
}

TEST(TestActor, TestUnknownMessage) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor();
	a->send(b, "unknown");
	EXPECT_EQ(b->getUnknown(), "unknown");
	a->send(b, "hello");
	EXPECT_EQ(b->getUnknown(), "");
}

TEST(TestActor, TestKill) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor(a);
	bool a_flag = false, b_flag = false;

	a->set_kill_flag(&a_flag);
	b->set_kill_flag(&b_flag);

	a->kill();

	EXPECT_EQ(a_flag, true);
	EXPECT_EQ(b_flag, true);
}

TEST(TestActor, TestFailed) {
	// Crear test actor padre e hijo
	TestActor *parent, *child(parent);

	// padre envía mensaje que el hijo no puede procesar
	parent->send(child, "throw");

	// hijo envía mensaje "failed" a mailbox del padre
	// a través de excepciones manejadas por el hijo
	EXPECT_EQ(parent->getReply(), "failed");
}
