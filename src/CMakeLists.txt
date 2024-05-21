cmake_minimum_required(VERSION 3.22)
project(STL)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g -Wall -Werror -Wextra")
set(CMAKE_CXX_STANDARD 17)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_subdirectory(stl/list)
add_subdirectory(stl/vector)
add_subdirectory(stl/stack)
add_subdirectory(stl/queue)
add_subdirectory(stl/map)
add_subdirectory(stl/tree)
add_executable(STL
        tests/tests.h
        tests/s21_avlTree_test.cc
        tests/s21_tests_queue.cc
        tests/s21_tests_map.cc
        tests/s21_tests_set.cc
        tests/s21_tests_list.cc
        tests/s21_tests_vector.cc
        tests/s21_tests_stack.cc

)

target_include_directories(STL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/stl)
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTEST_LIBRARIES} gtest_main)
message("Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")
message("Root source directory: ${CMAKE_SOURCE_DIR}")

