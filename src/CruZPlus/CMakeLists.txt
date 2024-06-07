set(CRUZ_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

configure_file(
	${SOURCE_DIR}/Configure.h.in
	${SOURCE_DIR}/Configure.h
)

file(GLOB_RECURSE SOURCE_FILES
	RELATIVE ${SOURCE_DIR}
	${SOURCE_DIR}/*.cpp
)
list(FILTER SOURCE_FILES EXCLUDE REGEX "Editor/.*" )

add_library(cruzplus-common ${SOURCE_FILES})

set_property(TARGET cruzplus-common PROPERTY CXX_STANDARD 20)
target_compile_options(cruzplus-common PRIVATE -W4)

find_package(GLM REQUIRED)

target_include_directories(cruzplus-common 
	PUBLIC .. "${GLM_INCLUDE_DIRS}")

target_link_libraries(cruzplus-common
	PUBLIC SFML::Window SFML::Graphics
	PUBLIC box2d
)