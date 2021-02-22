# CMakeList.txt : 최상위 CMake 프로젝트 파일, 전역 구성을 수행하고
# 여기에 하위 프로젝트를 포함합니다.
#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project ("Simpp")

SET(PROJECT_VERSION_MAJOR 0)
SET(PROJECT_VERSION_MINOR 1)

if (UNIX)
	SET(CMAKE_CXX_STANDARD 11)

	SET(CMAKE_C_COMPILER "g++")
	SET(CMAKE_CXX_COMPILER "g++")
	SET(GXX_STDLIB_FLAGS "-lstdc++")
endif (UNIX)

# 하위 프로젝트를 포함합니다.
add_subdirectory ("DEVSim++")
