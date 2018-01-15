cmake_minimum_required(VERSION 3.6)
project(ctd)

option(CTD_BUILD_TEST "build test" OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(ctd INTERFACE)
target_include_directories(ctd INTERFACE include/)

if(CTD_BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()
