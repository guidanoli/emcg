cmake_minimum_required(VERSION 3.0)
project(emcg)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

enable_testing()

add_subdirectory(src)