cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)
project(tinyxml2)
set(GENERIC_LIB_VERSION "2.1.0")
set(GENERIC_LIB_SOVERSION "2")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(tinyxml2 STATIC tinyxml2.cpp tinyxml2.h)
	
