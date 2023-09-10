cmake_minimum_required(VERSION 3.16)
project(TinyDL)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(./include)

file(GLOB_RECURSE SOURCE_FILES ./src/*)

add_executable(testAutograd "testAutoGrad.cpp" ${SOURCE_FILES})
