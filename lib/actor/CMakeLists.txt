cmake_minimum_required(VERSION 3.15)

project(actor
        VERSION 0.0.0
        DESCRIPTION "Libreria modelo actores"
        )

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
target_include_directories(actor PRIVATE include)
target_include_directories(actor PRIVATE src)

add_subdirectory(test)
