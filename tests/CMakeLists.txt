cmake_minimum_required(VERSION 3.14)

project(taglab-core-tests CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==== OPTIONS ====

option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

# ensure target can be found if top level
if(PROJECT_IS_TOP_LEVEL OR TEST_INSTALLED_VERSION)
    find_package(taglab-core CONFIG REQUIRED)
else()
    add_library(taglab::taglab-core ALIAS taglab-core)
endif()

# ==== DEPENDENCIES ====

find_package(doctest)

# ==== BUILDING TARGET ====

set(SOURCES main.cpp greeter/test_greeter.cpp)

list(TRANSFORM SOURCES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} doctest::doctest taglab::taglab-core)
# add private headers as well
target_include_directories(${PROJECT_NAME} PUBLIC ../src)

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
endif()

# ==== TESTING ====

enable_testing()

include(doctest)
doctest_discover_tests(${PROJECT_NAME})
