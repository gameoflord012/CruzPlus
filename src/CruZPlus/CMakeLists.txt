add_executable(CruZPlus 
	GameEntity/SpaceShip.cpp
	Editor/Board.cpp
	main.cpp
)

target_link_libraries(CruZPlus 
	SFML::Window SFML::Graphics box2d
)
