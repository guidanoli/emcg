add_executable(point point.cpp)
link_libraries(point OpenGL GLU)
target_link_libraries(point glh)
set_target_properties(point PROPERTIES FOLDER demos)