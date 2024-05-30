cmake_minimum_required (VERSION 3.8)
project (CruZPlus)

set(RESOURCE_OUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/CruZPlus)
set(CRUZ_RESOURCE_DIR ${CMAKE_SOURCE_DIR}/res)

file(
    COPY ${CRUZ_RESOURCE_DIR}
	DESTINATION ${RESOURCE_OUT_DIR})
    
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

add_subdirectory(ThirdParty)
add_subdirectory(src/CruZPlus)