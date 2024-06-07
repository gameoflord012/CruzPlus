cmake_minimum_required (VERSION 3.8)
project (CruZPlus)

set(CRUZ_RESOURCE_DIR "${CMAKE_SOURCE_DIR}/res")
     
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")
list(APPEND CRUZ_THIRDPARTY_DIR "${PROJECT_SOURCE_DIR}/ThirdParty")

add_subdirectory(ThirdParty)
add_subdirectory(src)