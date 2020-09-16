cmake_minimum_required(VERSION 3.15)

project(actor)

set(DESCRIPTION "Libreria modelo actores")

set(actor_VERSION_MAJOR 0)
set(actor_VERSION_MINOR 0)
set(actor_VERSION_PATCH 1)
set(actor_VERSION_STRING ${actor_VERSION_MAJOR}.${actor_VERSION_MINOR}.${actor_VERSION_PATCH})
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")


set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES
    src/actor.cpp
    )
include_directories(include)

add_library(actor SHARED ${SOURCE_FILES})
target_link_libraries(actor ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(actor PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
set_target_properties(actor PROPERTIES PUBLIC_HEADER include/)
set_target_properties(actor PROPERTIES PRIVATE src/)
set_target_properties(actor  PROPERTIES VERSION ${actor_VERSION_STRING} SOVERSION ${actor_VERSION_MAJOR})
SET_TARGET_PROPERTIES(actor PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(test)
