cmake_minimum_required(VERSION 3.0) 

project(OberservePatternpro)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

SET(SRC_LIST
    AllyCenter.cpp
)

set(code 2.Code)

include_directories(${CMAKE_SOURCE_DIR}/${code})

add_executable(OberservePattern ./${code}/main.cpp ${code}/${SRC_LIST})

# TARGET_LINK_LIBRARIES(test_ThreadPool pthread) 