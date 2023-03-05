
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Rules)

target_include_directories(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Mesh.h)
target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Sudoku.h)
target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Tile.h)
target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/TileSpace.h)

