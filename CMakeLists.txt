cmake_minimum_required(VERSION 3.23)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(Matrix main.cpp)

include_directories(Vector)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(gtests_run tests/test.cpp)
target_link_libraries(gtests_run gtest gtest_main)





# ctest things
#add_executable(tests tests/test.cpp)
#
#
#enable_testing()
#
#add_test(NAME tests
#        COMMAND $<TARGET_FILE:tests>)
