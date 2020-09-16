cmake_minimum_required(VERSION 3.15)

project(indexing-service)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES
        src/LinkChecker.cpp
        src/CrawlServer.cpp
        src/HttpGetter.cpp
        src/main.cpp
   )

include_directories(include)

#ADD libactor
add_executable(indexing-service ${SOURCE_FILES})
target_link_libraries(indexing-service actor)
