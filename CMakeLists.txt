cmake_minimum_required (VERSION 3.2)

project (cpp-commander)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 14)
SET(CPACK_GENERATOR "TGZ")

find_package(Boost COMPONENTS unit_test_framework system filesystem)
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("Commander")
add_subdirectory("examples")
add_subdirectory("tests")

include(CPack)

