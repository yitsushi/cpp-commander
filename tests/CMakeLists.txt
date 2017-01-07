set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB TEST_SRCS *.cpp)

foreach(testSrc ${TEST_SRCS})
  get_filename_component(testName ${testSrc} NAME_WE)
  add_executable(${testName} ${testSrc})
  target_link_libraries(${testName} ${Boost_LIBRARIES} commander)
  set_target_properties(${testName} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests)
  add_test(NAME ${testName}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests
    COMMAND ${CMAKE_BINARY_DIR}/bin/tests/${testName})
endforeach(testSrc)

#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} COMMANDER_TESTS_SOURCES)

#add_executable(commander-tests ${COMMANDER_TESTS_SOURCES})
#target_link_libraries(commander-tests commander ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
#add_test(commander-tests commander-tests)
