cmake_minimum_required(VERSION 3.15)

project(actor)

set(DESCRIPTION "Libreria modelo actores")

set(actor_VERSION_MAJOR 0)
set(actor_VERSION_MINOR 0)
set(actor_VERSION_PATCH 1)
set(actor_VERSION_STRING ${actor_VERSION_MAJOR}.${actor_VERSION_MINOR}.${actor_VERSION_PATCH})


set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/actor.cpp
        src/ActorManager.cpp
        include/ActorManager.h
        include/actor.h
   )
include_directories(include)
include_directories(src)

add_library(actor SHARED ${SOURCE_FILES})
set_target_properties(actor PROPERTIES PUBLIC_HEADER include/)
set_target_properties(actor  PROPERTIES VERSION ${actor_VERSION_STRING} SOVERSION ${actor_VERSION_MAJOR})


add_subdirectory(test)
