cmake_minimum_required(VERSION 3.0.0)
project(CS100_Lab3 VERSION 3.0.0)

add_subdirectory(${CMAKE_BINARY_DIR}/../googletest)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab3_tests 
    ../src/unit_tests.cpp
)

add_executable(lab3
    src/main.cpp
)

TARGET_LINK_LIBRARIES(lab3_tests gtest)
TARGET_COMPILE_DEFINITIONS(lab3_tests PRIVATE gtest_disable_pthreads=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)