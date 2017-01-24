add_library(DynamicCommand MODULE DynamicCommand.cpp)
target_link_libraries(DynamicCommand commander)
set_target_properties(DynamicCommand PROPERTIES PREFIX "command_")
set_target_properties(DynamicCommand PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/dynamic_commands")

