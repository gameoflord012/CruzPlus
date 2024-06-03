set(SPACE_SHOOTER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SPACE_SHOOTER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})


file(GLOB_RECURSE SPACE_SHOOTER_SOURCE_FILES
	RELATIVE ${SPACE_SHOOTER_SOURCE_DIR}
	${SPACE_SHOOTER_SOURCE_DIR}/*.cpp
)

add_executable(SpaceShooter ${SPACE_SHOOTER_SOURCE_FILES})
set_property(TARGET SpaceShooter PROPERTY CXX_STANDARD 20)
target_include_directories(SpaceShooter PRIVATE ..)

target_link_libraries(SpaceShooter 
	cruzplus-common
)

target_compile_options(SpaceShooter PRIVATE -W4)
