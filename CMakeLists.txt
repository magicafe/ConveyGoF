cmake_minimum_required(VERSION 3.0.0)
project(ConveyGoF VERSION 0.1.0)

# comment the line below to remove big integer support
# add_compile_definitions(BIG_INT)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE "Release")

add_executable(deadcells main.cpp)

