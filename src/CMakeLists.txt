# GL dependent
if (EMCG_HAS_GL)
	add_subdirectory(glh)
	add_subdirectory("function")
	add_subdirectory(point)
	add_subdirectory(plot)
endif()

# GL independent
add_subdirectory(rational)
add_subdirectory(vector)