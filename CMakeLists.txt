cmake_minimum_required (VERSION 3.7)

project (cpp-commander)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 14)
SET(CPACK_GENERATOR "TGZ")

add_subdirectory("src")
add_subdirectory("examples")

include_directories("examples")

include(CPack)

