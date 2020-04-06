cmake_minimum_required(VERSION 3.0)
project(emcg)

option(EMCG_TEST "Enable test cases" OFF)

if (EMCG_TEST)
	enable_testing()
endif()

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(
	${OPENGL_INCLUDE_DIRS}
	${GLUT_INCLUDE_DIRS})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
add_subdirectory(src)