cmake_minimum_required(VERSION 3.5)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter ip_filter.cpp)
