cmake_minimum_required(VERSION 2.8.4)
project(CP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES A_Star.cpp)
add_executable(CP ${SOURCE_FILES})
LINK_LIBRARIES(CP cppunit)
