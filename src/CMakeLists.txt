# ==== BUILDING TARGET ====

set(HEADERS)

set(SOURCES greeter/greeter.h greeter/greeter.cpp)

list(TRANSFORM HEADERS PREPEND ${PROJECT_SOURCE_DIR}/include/)
list(TRANSFORM SOURCES PREPEND ${PROJECT_SOURCE_DIR}/src/)

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_include_directories(
    ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra -Werror)
elseif(MSVC)
    target_compile_options(${PROJECT_NAME} PUBLIC /W4 /WX)
endif()
