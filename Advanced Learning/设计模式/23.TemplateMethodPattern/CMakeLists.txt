cmake_minimum_required(VERSION 3.0) 

project(TemplateMethodPattern)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

set(code 2.Code)

include_directories(${CMAKE_SOURCE_DIR}/${code}/inc)

add_executable(TemplateMethod ./${code}/main.cpp)