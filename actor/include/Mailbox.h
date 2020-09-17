//
// Created by darkwayc0de on 6/6/20.
//

#ifndef ACTOR_MAILBOX_H
#define ACTOR_MAILBOX_H

#include <queue>

#include <mutex>
#include <thread>
#include <condition_variable>
#include <actors_global.h>
#include <iostream>


template <typename Message>
class NOT_EXPORTED Mailbox {
private:
    using  queue = std::queue<Message>;
    queue mailbox_;
    std::mutex  mutex_;
    std::condition_variable noempty_;
public:

    Mailbox() = default;

    void push(const Message& message){
        std::lock_guard<std::mutex> lock(mutex_);
        mailbox_.push(message);
        noempty_.notify_one();
    }
    void push(Message&& message){
        std::lock_guard<std::mutex> lock(mutex_);
        mailbox_.push(std::move(message));
        noempty_.notify_one();
    }

    std::optional<Message> pop(const std::chrono::milliseconds& rel_time){

        std::unique_lock<std::mutex> lock(mutex_);
           bool noemptty = noempty_.wait_for(lock, rel_time,[this]{
                     return !mailbox_.empty();
                });
           if(noemptty){
                auto message = std::move(mailbox_.front());
                mailbox_.pop();
                return  message;
           }
        return {};
    }

    void clear(){
        std::lock_guard<std::mutex> lock(mutex_);
        mailbox_.swap(queue());
    }

    bool empty(){
        std::lock_guard<std::mutex> lock(mutex_);
        return  mailbox_.empty();
    }

private:

};


#endif //ACTOR_MAILBOX_H
