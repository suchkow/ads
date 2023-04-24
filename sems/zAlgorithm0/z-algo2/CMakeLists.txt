cmake_minimum_required(VERSION 3.5)

project(z-algo2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(z-algo2 main.cpp
               alice.txt)
