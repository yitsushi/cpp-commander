set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.63.0 COMPONENTS unit_test_framework REQUIRED) 

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

  aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} COMMANDER_TESTS_SOURCES)

  add_executable(commander-tests ${COMMANDER_TESTS_SOURCES})
  target_link_libraries(commander-tests commander ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
  add_test(commander-tests commander-tests)
endif()
