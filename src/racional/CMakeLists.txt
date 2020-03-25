add_library(racional racional.cpp racional.hpp)
target_include_directories(racional PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(racional PROPERTIES
	FOLDER libraries)