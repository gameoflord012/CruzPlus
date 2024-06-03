set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SOURCE_FILES
	RELATIVE ${SOURCE_DIR}
	${SOURCE_DIR}/../*.cpp
)

add_library(cruzplus-editor ${SOURCE_FILES})

set_property(TARGET cruzplus-editor PROPERTY CXX_STANDARD 20)
target_compile_options(cruzplus-editor PRIVATE -W4)
target_compile_definitions(cruzplus-editor PUBLIC "CRUZ_EDITOR")

target_include_directories(cruzplus-editor PUBLIC ..)
target_link_libraries(cruzplus-editor
	PUBLIC SFML::Window SFML::Graphics
	PUBLIC box2d
	PUBLIC imgui-sfml
)