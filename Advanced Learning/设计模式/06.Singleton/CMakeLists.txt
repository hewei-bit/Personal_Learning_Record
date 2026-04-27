cmake_minimum_required(VERSION 3.0) 

project(SingletonPattern)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

set(code 2.code)

include_directories(${CMAKE_SOURCE_DIR}/${code})

add_executable(Singleton ./${code}/main.cpp)