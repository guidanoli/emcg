add_executable(plot plot.cpp)
link_libraries(plot OpenGL GLU glh)
target_link_libraries(plot glh function)
set_target_properties(plot PROPERTIES FOLDER demos)