cmake_minimum_required(VERSION 3.0.0)
project(CS100_Lab3 VERSION 3.0.0)

add_subdirectory(${CMAKE_BINARY_DIR}/../googletest)

set(CMAKE_CXX_STANDARD 11)

add_executable(composite_tests 
    ../src/unit_tests.cpp
)

add_executable(composite_pattern
    src/main.cpp
)

TARGET_LINK_LIBRARIES(composite_tests gtest)
TARGET_COMPILE_DEFINITIONS(composite_tests PRIVATE gtest_disable_pthreads=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)