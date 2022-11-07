cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_HOME_DIRECTORY}/../)

file(GLOB SRCS ../*.cpp)
# file(GLOB_RECURSE REMOVE_CMAKE "cmake-build-debug/*")
# list(REMOVE_ITEM ${SRCS} ${REMOVE_CMAKE})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp unit_test.cpp ${SRCS})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
