cmake_minimum_required(VERSION 3.0)

# Creates a default target for a class with
# source file classname.cpp and header file
# classname.hpp
function(add_class classname)
	add_library(${classname} "${classname}.cpp" "${classname}.hpp")
	target_include_directories(${classname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
	set_target_properties(${classname} PROPERTIES FOLDER libraries)
endfunction()

# Creates a default test for class of target
# named classname, and test file t.classname.cpp
function(add_class_test classname)
	add_executable("${classname}test" "t.${classname}.cpp")
	link_libraries("${classname}test" ${classname})
	set_target_properties("${classname}test" PROPERTIES FOLDER tests)
	add_test(NAME ${classname} COMMAND "${classname}test")
endfunction()