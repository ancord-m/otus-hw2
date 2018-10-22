cmake_minimum_required(VERSION 3.5)

#project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

project(ip_filter VERSION 0.0.1)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter ip_filter.cpp)

set_target_properties(ip_filter PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic;-Wall;-Wextra
)
