# Add dyanmic commands
add_subdirectory("dynamic_commands")

# Add example executable
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/commands COMMANDS)
add_executable(example main.cpp ${COMMANDS})
target_link_libraries(example commander)
install(TARGETS example RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/bin")
