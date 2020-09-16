cmake_minimum_required(VERSION 3.15)

project(indexing-service CXX)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES
        src/LinkChecker.cpp
        src/CrawlServer.cpp
        src/HttpGetter.cpp
        src/Curlflecher.cpp
        src/main.cpp
   )

include_directories(include)

find_package(PkgConfig REQUIRED)
# these calls create special `PkgConfig::<MODULE>` variables
pkg_check_modules(YOUR_PKG REQUIRED IMPORTED_TARGET libcurl)

#ADD libactor
include_directories(../actor/include)
add_library(actor SHARED IMPORTED GLOBAL)
set_target_properties(actor PROPERTIES IMPORTED_LOCATION
        "${PROJECT_SOURCE_DIR}/../actor/cmake-build-debug/libactor.so")

add_executable(indexing-service ${SOURCE_FILES})
target_link_libraries(indexing-service PRIVATE actor PUBLIC PkgConfig::YOUR_PKG)
