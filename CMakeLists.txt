cmake_minimum_required(VERSION 3.14)

project(corrupted-spirit)

set(CMAKE_CXX_STANDARD 17)
set(Project_VERSION "0.1.0")

add_executable(corrupted-spirit)

target_include_directories(corrupted-spirit
	PRIVATE
		"C:/Code/boost_1_70_0")

target_sources(corrupted-spirit
	PRIVATE
		x3/employee/main.cpp
		x3/employee/rules.cpp
)
