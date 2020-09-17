//
// Created by darkwayc0de on 27/5/20.
//

#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "test_actor.h"
#include "actor.h"

TEST(TestActor,slotIsCalledWhenMessageIsSend){
    TestActor* actorA_;
    TestActor* actorB_;
    actorA_ = ActorManager::instance()->spawn<TestActor>();
    actorB_ = ActorManager::instance()->spawn<TestActor>();
    int arg = 10;
    EXPECT_TRUE(actorA_->test_sender(actorB_, "update_int", arg));
    sleep(1);
    std::cout << "[+] Reached checkpoint #1.\n";
    EXPECT_EQ(actorB_->getIntProperty(), arg);
    ActorManager::kill(actorA_);
    ActorManager::kill(actorB_);
};

/*
 * TODO Sender es nulo cuando no hay mensjaes
TEST(TestActor, TestSenderNullptr) {
	TestActor* a = new TestActor(nullptr);
    EXPECT_EQ(a->test_sender(), nullptr);
}
    TODO El sender es correcto cuando un mensaje llega
TEST(TestActor, TestSenderRemitente) {
	TestActor* a = new TestActor();
	TestActor* b = new TestActor();
	a->send(b, "hello");
	EXPECT_EQ(b->test_sender(), "hello");
}
*/
TEST(TestActor, TestReply) {
    //TODO  se puede responder a sender actors
    /*
	TestActor* a = new TestActor();
	TestActor* b = new TestActor();
	a->send(b, "hello");
	/// EXPECT_EQ(b->getReply(), "world");
	std::string  str1 = "que tal";
	std::string  str2;
	b->Reply(str1);
	str2 = a->getReply();
	EXPECT_EQ(str1,str2);
    */
}

TEST(TestActor, TestUnknownMessage) {
    /*
     *
     * //TODO  Cuando llega un mensajedesconocido se llama al slot mensaje desconocido
     */

}

TEST(TestActor, TestKill) {
    /*
    TestActor* actorA_;
    actorA_ = ActorManager::instance()->spawn<TestActor>();
    EXPECT_TRUE(actorA_->test_sender(actorA_,"kill"));
    sleep(1);
    EXPECT_TRUE(ActorManager::threadlive(actorA_) == false );
    ActorManager::kill(actorA_);
    */
}

TEST(TestActor, TestFailed) {
    /* TODO Un actor es notificado cuando el hijo falla
     *  cuando surge una exception
     */
    /*
    TestActor* actorA_;
    actorA_ = ActorManager::instance()->spawn<TestActor>();
    auto child = actorA_->spawnchildActorAndFail();
    ActorManager::kill(child);
    ActorManager::kill(actorA_);
    */
}
