cmake_minimum_required(VERSION 3.12...3.23)
project(MathLibrary)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MathLib INTERFACE) 

add_executable(ManualTest EXCLUDE_FROM_ALL 
    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

#---Google Test---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(AutoTest
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/MatrixTest.cpp
)
target_link_libraries(
  AutoTest
  MathLib
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(AutoTest)
#---Google Test---