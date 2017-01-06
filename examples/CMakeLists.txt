
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/commands COMMANDS)

add_executable(cpp-commander main.cpp ${COMMANDS})


target_link_libraries(cpp-commander commander)

install(TARGETS cpp-commander RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/bin")


