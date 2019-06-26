cmake_minimum_required(VERSION 3.14)
project(GreedyBackpack)

set(CMAKE_CXX_STANDARD 17)

add_executable(GreedyBackpack main.cpp Element.cpp Element.h Backpack.cpp Backpack.h RandomNumberGenerator.h RandomNumberGenerator.cpp)