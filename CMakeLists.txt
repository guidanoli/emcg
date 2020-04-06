cmake_minimum_required(VERSION 3.0)
project(emcg)

option(BUILD_TESTING "Enable test cases" ON)
option(EMCG_HAS_GL "Has graphic libraries" ON)

if (EMCG_HAS_GL)

	find_package(OpenGL)
	find_package(GLUT)

	if (OPENGL_FOUND)
		include_directories(${OPENGL_INCLUDE_DIRS})
	endif()

	if (GLUT_FOUND)
		include_directories(${GLUT_INCLUDE_DIRS})
	endif()
	
	if (NOT OPENGL_FOUND OR
		NOT GLUT_FOUND)
		
		# If some GL wasn't found
		set(EMCG_HAS_GL OFF)
		
	endif()
	
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(src)