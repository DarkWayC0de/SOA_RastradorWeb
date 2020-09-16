//
// Created by darkwayc0de on 16/9/20.
//

#include "LinkChecker.h"

LinkChecker::LinkChecker(Actor *actor) : Actor(actor) {

}

void LinkChecker::request(const std::string &url, int depth) {
    // TODO: Crear un HttpGetter y pedirle que procesese la url
}

void LinkChecker::checkUrl(const std::string &url, int depth) {
    //TODO: Comprobar si la url ha sido procesada, afirmativo ingnoramos,
    // neg crear httpgeter que procese la url con depth -1
    // si depth == 0 guardar url pero no procesar
}

void LinkChecker::done() {
    //TODO Comprobar si es el ultimo httpgeter. Si es asi devolver lista urls al crawlserver
    // respuesta a result

}

