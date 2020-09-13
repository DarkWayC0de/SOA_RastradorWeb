//
// Created by darkwayc0de on 9/6/20.
//

#ifndef ACTOR_DELEGATE_H
#define ACTOR_DELEGATE_H

#include <functional>
#include <string>
#include <unordered_map>
#include <iostream>
#include <any>
class Delegate{
public:
    template <typename... Types>
    Delegate(std::function<void (Types...)> handler);

    template<typename... Types>
    void operator()(Types&&... args);
private:
    std::any handler_;
};




#endif //ACTOR_DELEGATE_H
