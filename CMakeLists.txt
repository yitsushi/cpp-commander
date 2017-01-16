cmake_minimum_required (VERSION 3.2)

project (commander)

set(PROJECT_TEST_NAME "${PROJECT_NAME}_test")

if(CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_COMPILER_IS_GNUCXX AND WITHCOVERAGE)
  message(WARNING "Coverage enabled")
  set(COVERAGE_ENABLED true)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 14)
SET(CPACK_GENERATOR "TGZ")

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

find_package(Boost COMPONENTS unit_test_framework system filesystem)
enable_testing()

if(COVERAGE_ENABLED)
  find_program(GCOV_PATH gcov)
  find_program(LCOV_PATH lcov)
  find_program(GENHTML_PATH genhtml)

  if(NOT GCOV_PATH)
    message(FATAL_ERROR "gcov not found! Aborting...")
  endif()

  if(NOT LCOV_PATH)
    message(FATAL_ERROR "lcov not found! Aborting...")
  endif()

  if(NOT GENHTML_PATH)
    message(FATAL_ERROR "genhtml not found! Aborting...")
  endif()

  message(WARNING ${GENHTML_PATH})

  add_definitions(-fprofile-arcs -ftest-coverage)
  link_libraries(gcov)

  add_custom_target(coverage
    ${LCOV_PATH} --directory . --zerocounters

    command ${PROJECT_TEST_NAME}

    command ${LCOV_PATH} --directory . --capture --output-file coverage.info
    command ${LCOV_PATH} --remove coverage.info 'tests/*' '/usr/*' --output-file coverage.info.cleaned
    command ${GENHTML_PATH} -o coverage coverage.info.cleaned --legend -s
    command ${CMAKE_COMMAND} -E remove coverage.info coverage.info.cleaned

    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Resetting code coverage counters to zero.\nProcessing code coverage counters and generating report."
  )
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("Commander")
add_subdirectory("examples")
add_subdirectory("tests")

include(CPack)

