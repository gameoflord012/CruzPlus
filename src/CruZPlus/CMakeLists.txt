set(CRUZ_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CRUZ_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

configure_file(
	${CRUZ_SOURCE_DIR}/Configure.h.in
	${CRUZ_SOURCE_DIR}/Configure.h
)

file(GLOB_RECURSE CRUZ_SOURCE_FILES
	RELATIVE ${CRUZ_SOURCE_DIR}
	${CRUZ_SOURCE_DIR}/*.cpp
)

add_executable(CruZPlus ${CRUZ_SOURCE_FILES})
set_property(TARGET CruZPlus PROPERTY CXX_STANDARD 20)
target_include_directories(CruZPlus PRIVATE ..)

target_link_libraries(CruZPlus 
	SFML::Window SFML::Graphics
	imgui-sfml
	box2d
)

target_compile_options(CruZPlus PRIVATE -W4)
