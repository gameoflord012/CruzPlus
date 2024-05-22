cmake_minimum_required (VERSION 3.8)

set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/res)

include(CMakePrintHelpers)  

project (CruZPlus)

add_subdirectory(ThirdParty/SFML)
add_subdirectory(ThirdParty/box2d)
add_subdirectory(src)