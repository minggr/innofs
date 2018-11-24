cmake_minimum_required(VERSION 2.8)
project(innofs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

file(GLOB SOURCES "*.cc" "*.h")

add_executable(page_info ${SOURCES})
