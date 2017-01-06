aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} COMMANDER_SOURCES)
add_library(commander STATIC ${COMMANDER_SOURCES})
add_library(commander_shared SHARED ${COMMANDER_SOURCES})
