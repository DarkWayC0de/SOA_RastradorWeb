cmake_minimum_required(VERSION 3.15)
project(soa_1920_rastreador_web_diego_oscar)

if (CMAKE_COMPILER_IS_GNUCXX)
    message("Building with llvm Code Coverage tools")
    set(CMAKE_CXX_FLAGS  "--coverage")
endif ()
set(CMAKE_CXX_STANDARD 17)

add_executable(soa_1920_rastreador_web_diego_oscar
        src/main.cpp)
