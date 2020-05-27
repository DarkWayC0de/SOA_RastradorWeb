//
// Created by darkwayc0de on 27/5/20.
//
#include "gtest/gtest.h"
#include "../include/Actor.h"

TEST_F(Actor, testsendernulptr){
  ASSERT_EQ(sender(), nullptr);
}

TEST_F(Actor, testsenderremitente){
  //aqui falta algo
  ASSERT_NE(sender(), nullptr);
}

TEST_F(Actor,testreply){
  reply();
  //Falta comprobacion
}
TEST_F(Actor,testunknownMessage){
  //std::string mensage = "hola";
  unknownMessage(mensage);
  //Falta comprobacion
}

TEST_F(Actor,testkill){
  kill();
  //falta la comprobacion
}
TEST_F(Actor,testfalled){
  //Crear hijo
  //hacer que falle hijo por manejo de ecepciones
  // comprobar notificacion de fallo

}