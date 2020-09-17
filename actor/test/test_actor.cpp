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
    EXPECT_EQ(actorB_->getIntProperty(), arg);
    ActorManager::kill(actorA_);
    ActorManager::kill(actorB_);

};

/*
 * TODO Sender es nulo cuando no hay mensjaes
TEST(TestActor, TestSenderNullptr) {
	TestActor* a = new TestActor(nullptr);
    EXPECT_EQ(a->test_sender(), nullptr);
}*/
TEST(TestActor, TestSenderRemitente) {
	auto a = ActorManager::instance()->spawn<TestActor>();
	auto b = ActorManager::instance()->spawn<TestActor>();
	a->test_sender(b,"senderiscorrect");
	sleep(1);
	EXPECT_EQ(b->getSender(), a);
}

TEST(TestActor, TestReply) {
    //TODO  se puede responder a sender actors
    auto a = ActorManager::instance()->spawn<TestActor>();
    auto b = ActorManager::instance()->spawn<TestActor>();
    a->test_sender(b,"replygetIntProperrty",30);
    sleep(1);
    EXPECT_EQ(a->getIntProperty(), 30);
}

TEST(TestActor, TestUnknownMessage) {
    /*
     *
     * //TODO  Cuando llega un mensajedesconocido se llama al slot mensaje desconocido
     */
    auto a = ActorManager::instance()->spawn<TestActor>();
    auto b = ActorManager::instance()->spawn<TestActor>();
    a->test_sender(b, "unknown_msg", 30);
    sleep(1);
    EXPECT_EQ(b->getUnknownProperty(), true);
}

TEST(TestActor, TestKill) {
    TestActor* actorA_;
    actorA_ = ActorManager::instance()->spawn<TestActor>();
    EXPECT_TRUE(actorA_->test_sender(actorA_,"kill"));
    sleep(1);
    EXPECT_TRUE((ActorManager::threadlive(actorA_) == false) );
}

TEST(TestActor, TestFailed) {
    /* TODO Un actor es notificado cuando el hijo falla
     *  cuando surge una exception
     */
    auto parent = ActorManager::instance()->spawn<TestActor>();
    auto child = parent->spawnchildActorAndFail();
    EXPECT_EQ(parent->getChildFailure(), true);
}
