cmake_minimum_required(VERSION 3.15)

project(soa_1920_rastreador_web_diego_oscar)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/main.cpp
        src/actor/actor.cpp
        src/actor/ActorManager.cpp
        include/actor/ActoManager.h
        include/actor/actor.h
        )

include_directories(include)
include_directories(src)

add_executable(soa_1920_rastreador_web_diego_oscar ${SOURCE_FILES})

add_subdirectory(test)