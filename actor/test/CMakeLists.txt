cmake_minimum_required(VERSION 3.15)

project(actor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE debug)
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()
# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()




# coverage
if (CMAKE_COMPILER_IS_GNUCXX)
    message("Building with llvm Code Coverage tools")
    set(CMAKE_CXX_FLAGS  "--coverage")
endif ()

set(SOURCE_TEXT ../src/actor.cpp)
include_directories(../include)

add_executable(actor_test test_actor.h test_actor.cpp ${SOURCE_TEXT})

target_link_libraries(actor_test PRIVATE gtest gtest_main)

add_test(NAME example_test COMMAND actor_test)

add_custom_command(TARGET actor_test
	POST_BUILD
	COMMAND actor_test)
