cmake_minimum_required(VERSION 3.15)

project(indexing-service)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
      src/main.cpp
   )

include_directories(include)

#ADD libactor
include_directories(../actor/include)
add_library(actor SHARED IMPORTED GLOBAL)
set_target_properties(actor PROPERTIES IMPORTED_LOCATION
        "${PROJECT_SOURCE_DIR}/../actor/cmake-build-debug/libactor.so")


add_executable(indexing-service ${SOURCE_FILES})


target_link_libraries(indexing-service PRIVATE actor)
