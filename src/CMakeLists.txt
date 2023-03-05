
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Rules)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Input)

target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Mesh.cpp)
target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Sudoku.cpp)
target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Tile.cpp)
target_sources(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/TileSpace.cpp)
