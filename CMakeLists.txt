cmake_minimum_required(VERSION 3.5)

set(ENV{TRAVIS_BUILD_NUMBER} 1)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(INCLUDE_DIR include)

set(TESTS_DIR test)

set(SRC_DIR src)

set(SRC_LIST ${SRC_DIR}/parser.cpp
			 ${SRC_DIR}/sorter.cpp
			 ${SRC_DIR}/printer.cpp
   )

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter ${SRC_DIR}/ip_filter.cpp ${SRC_LIST})

add_executable(ip_filter_tests ${TESTS_DIR}/ip_filter_tests.cpp ${SRC_LIST})

set_target_properties(ip_filter ip_filter_tests PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic;-Wall;-Wextra
)

target_include_directories(ip_filter PRIVATE ${INCLUDE_DIR})

set_target_properties(ip_filter_tests PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_include_directories(ip_filter_tests PRIVATE ${INCLUDE_DIR})

target_link_libraries(ip_filter_tests
	${Boost_LIBRARIES}
)

message(STATUS "My include directories:")

get_target_property(IN_DIR ip_filter_tests INCLUDE_DIRECTORIES)

message(STATUS ${IN_DIR})

enable_testing()