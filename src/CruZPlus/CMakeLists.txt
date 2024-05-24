add_executable(CruZPlus 
	GameEntity/SpaceShip.cpp
	Editor/Board.cpp
	Game.cpp
	main.cpp
)

target_compile_options(CruZPlus PRIVATE -W3)

target_link_libraries(CruZPlus 
	SFML::Window SFML::Graphics box2d
)
