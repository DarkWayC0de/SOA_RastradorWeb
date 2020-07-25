//
// Created by darkwayc0de on 27/5/20.
//

#include <memory>
#include "gtest/gtest.h"
#include "test_actor.h"

TEST(TestActor, TestSenderNullptr) {
	TestActor* a = new TestActor();
	/// EXPECT_EQ(a->sender().has_value(), false);
     EXPECT_EQ(a->sender(), nullptr);
}

TEST(TestActor, TestSenderRemitente) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor();
	a->send(b, "hello");
	/// EXPECT_EQ(b->sender(), "hello");
	EXPECT_EQ(  &(b->sender()), &a );
}

TEST(TestActor, TestReply) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor();
	a->send(b, "hello");
	/// EXPECT_EQ(b->getReply(), "world");
	std::string  str1 = "que tal";
	std::string  str2;
	b->Reply(str1);
	str2 = a->getReply();
	EXPECT_EQ(str1,str2);
}

TEST(TestActor, TestUnknownMessage) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor();
	a->send(b, "unknown");
	/// EXPECT_EQ(b->getReply(), "unknown");
	a->send(b, "hello");
	/// EXPECT_EQ(b->getReply(), "world");
	EXPECT_EQ( b ->unknownMenssage(), {"unknown","hello"});
}

TEST(TestActor, TestKill) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor(a);
	/// bool a_flag = false, b_flag = false;

	/// a->set_kill_flag(&a_flag);
	/// b->set_kill_flag(&b_flag);

	/// a->kill();

	/// EXPECT_EQ(a_flag, true);
	/// EXPECT_EQ(b_flag, true);

	// hasta donde entiendo kill tendría q
	// ser private(por eso es un sucidio porque
	// el propio actor decide morir) o como poco protected  y
	// seria auto destrucion del propio objeto

}

TEST(TestActor, TestFailed) {
	// Crear test actor padre e hijo
	TestActor *parent = new TestActor();
	TestActor *child  = new TestActor(parent);

	// padre envía mensaje que el hijo falla al procesar
	// mediante ecepcion
	parent->send(child, "throw");

	// hijo envía mensaje "failed" a mailbox del padre
	// a través de excepciones manejadas por el hijo
    /// child->getReply();
    /// EXPECT_EQ(parent->sender(), "failed");
    EXPECT_EQ(parent->getReply(), "failed");
}
