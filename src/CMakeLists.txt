set(RESOURCE_OUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/CruZPlus)

file(COPY ${RESOURCE_DIR}
	DESTINATION ${RESOURCE_OUT_DIR})

include_directories(.)

add_subdirectory(CruZPlus)