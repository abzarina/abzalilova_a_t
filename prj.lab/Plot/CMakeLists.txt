cmake_minimum_required(VERSION 3.17)
project(plot)

add_executable(plot main.cpp)
include_directories(/usr/local/include)

find_package(Matplot++ REQUIRED)
target_link_libraries(plot Matplot++::matplot)