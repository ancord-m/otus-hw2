cmake_minimum_required(VERSION 3.5)

set(ENV{TRAVIS_BUILD_NUMBER} 1)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter src/ip_filter.cpp)

set(TESTS_DIR test/)

set(INCLUDE_DIR include/)

set(SRC_UNDER_TEST src/parser.cpp)

add_executable(ip_filter_tests ${TESTS_DIR}/ip_filter_tests.cpp ${SRC_UNDER_TEST})

set_target_properties(ip_filter ip_filter_tests PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic;-Wall;-Wextra
)

set_target_properties(ip_filter_tests PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_include_directories(ip_filter_tests PRIVATE ${INCLUDE_DIR})

target_link_libraries(ip_filter_tests
	${Boost_LIBRARIES}
)
