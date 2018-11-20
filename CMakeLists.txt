cmake_minimum_required(VERSION 3.5)

#project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(INCLUDE_DIR include)

set(TESTS_DIR test)

set(SRC_DIR src)

set(SRC_LIST ${SRC_DIR}/parser.cpp
			 ${SRC_DIR}/sorter.cpp
			 ${SRC_DIR}/printer.cpp
			 ${SRC_DIR}/filter.cpp
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

enable_testing()

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT leon8005@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

add_test(GotEmptyString_NothingFound ip_filter_tests)
add_test(GotTabSeparatedString_CapturedAllBeforeFirstTab ip_filter_tests)