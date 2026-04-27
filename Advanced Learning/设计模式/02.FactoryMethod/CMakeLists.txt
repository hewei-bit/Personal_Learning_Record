cmake_minimum_required(VERSION 3.0) 

project(StrategyPatternpro)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(StrategyPattern main.cpp)