cmake_minimum_required(VERSION 3.10)

project(corrupted-spirit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Og -g -fsanitize=address,undefined")
set(Project_VERSION "0.1.0")

add_executable(corrupted-spirit x3/employee/main.cpp x3/employee/rules.cpp)

target_include_directories(corrupted-spirit PRIVATE "~/custom/boost_1_70_0")
