cmake_minimum_required(VERSION 3.0)
project(emcg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTING "Enable test cases" ON)

find_package(OpenGL)
find_package(GLUT)

if (OPENGL_FOUND)
	include_directories(${OPENGL_INCLUDE_DIRS})
endif()

if (GLUT_FOUND)
	include_directories(${GLUT_INCLUDE_DIRS})
endif()

set(EMCG_HAS_GL (OPENGL_FOUND AND GLUT_FOUND))

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(src)