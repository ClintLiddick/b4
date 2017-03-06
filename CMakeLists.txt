cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(b4 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv7-a -mcpu=cortex-a8 -mfloat-abi=hard")

add_executable(hello
  src/hello_cross.cpp)

# set_property(TARGET hello PROPERTY CXX_STANDARD 11)
# set_property(TARGET hello PROPERTY CXX_STANDARD_REQUIRED ON)
