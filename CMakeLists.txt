cmake_minimum_required(VERSION 3.5)

#project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

project(ip_filter VERSION 0.0.1)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(src/)

add_executable(ip_filter src/ip_filter.cpp)

add_executable(ip_filter_tests test/ip_filter_tests.cpp)

set_target_properties(ip_filter ip_filter_tests PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic;-Wall;-Wextra
)

set_target_properties(ip_filter_tests PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(ip_filter_tests
	${Boost_LIBRARIES}
)
