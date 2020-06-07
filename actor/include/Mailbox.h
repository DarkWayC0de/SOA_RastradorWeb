//
// Created by darkwayc0de on 6/6/20.
//

#ifndef ACTOR_MAILBOX_H
#define ACTOR_MAILBOX_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include "actors_global.h"
// TODO revisar si es not_exported o exported
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
        mailbox_.push(message);
        noempty_.notify_one();
    }

    Message pop(){
        std::unique_lock<std::mutex> lock(mutex_);
        while(mailbox_.empty()){
            noempty_.wait(lock);
        }
        auto message = std::move(mailbox_.front());
        mailbox_.pop();
        return  message;
    }

    void clear(){
        std::lock_guard<std::mutex> lock(mutex_);
        mailbox_.swap( queue());
    }

    bool empty(){
        std::lock_guard<std::mutex> lock(mutex_);
        return  mailbox_.empty();
    }

private:

};


#endif //ACTOR_MAILBOX_H
