cmake_minimum_required(VERSION 3.14)

project(
    taglab-core
    VERSION $ENV{VERSION}
    LANGUAGES CXX)

# ==== INCLUDE GUARDS ====

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
            "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
    )
endif()

# ==== OPTIONS ====

option(ENABLE_TESTS "Enable building tests" ON)

# ==== CONFIGURATION ====

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# ==== DEPENDENCIES ====

set(CMAKE_MODULE_PATH $ENV{CMAKE_MODULE_PATH})

include(PackageProject)
include(Format)
include(cmake-scripts/tools)

# ==== TOOLS ====

clang_tidy()

# ==== SUBPROJECTS ====

add_subdirectory(src)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()

# ==== INSTALL ====

packageProject(
    NAME
    ${PROJECT_NAME}
    VERSION
    ${PROJECT_VERSION}
    NAMESPACE
    taglab
    BINARY_DIR
    ${PROJECT_BINARY_DIR}
    INCLUDE_DIR
    ${PROJECT_SOURCE_DIR}/include
    INCLUDE_DESTINATION
    include/${PROJECT_NAME}-${PROJECT_VERSION}
    VERSION_HEADER
    "${VERSION_HEADER_LOCATION}"
    COMPATIBILITY
    SameMajorVersion
    # DEPENDENCIES "fmt 9.1.0"
)
