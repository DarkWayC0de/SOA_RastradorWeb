//
// Created by darkwayc0de on 9/6/20.
//

#include "Delegate.h"
template<typename... Types>
Delegate::Delegate(std::function<void(Types...)> handler):handler_(handler) {}

template<typename... Types>
void Delegate::operator()(Types &&... args) {
    std::invoke(std::any_cast<std::function<void (Types...)>>(handler_), std::forward<Types>(args)...);
}