cmake_minimum_required(VERSION 3.14)

project(taglab-core-tests CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==== DEPENDENCIES ====

find_package(doctest)

# ==== BUILDING TARGET ====

set(SOURCES main.cpp test_locations_and_entries.cpp)

list(TRANSFORM SOURCES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} doctest::doctest taglab-core)

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
endif()

# ==== TESTING ====

enable_testing()

include(doctest)
doctest_discover_tests(${PROJECT_NAME})
