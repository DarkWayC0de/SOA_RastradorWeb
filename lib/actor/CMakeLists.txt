cmake_minimum_required(VERSION 3.15)

project(libactor)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/actor.cpp
        src/ActorManager.cpp
        include/ActorManager.h
        include/actor.h
        )

include_directories(include)
include_directories(src)

add_library(libactor ${SOURCE_FILES})

add_subdirectory(test)