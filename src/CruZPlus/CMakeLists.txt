file(GLOB_RECURSE source_files
	RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(CruZPlus ${source_files})

target_compile_options(CruZPlus PRIVATE -W)

target_link_libraries(CruZPlus 
	sfml-window sfml-graphics box2d
)
