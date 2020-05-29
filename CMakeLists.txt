cmake_minimum_required(VERSION 3.15)

project(soa_1920_rastreador_web_diego_oscar)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
      src/main.cpp
        )

include_directories(include)

# ADD Actorlib
include_directories(lib/actor/include)
add_subdirectory(lib/actor)

add_executable(rastreadorweb ${SOURCE_FILES})

target_link_libraries(rastreadorweb actor)
