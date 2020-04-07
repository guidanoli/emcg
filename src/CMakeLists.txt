# GL dependent
if (EMCG_HAS_GL)
	add_subdirectory(point)
endif()

# GL independent
add_subdirectory(rational)
add_subdirectory(vector)