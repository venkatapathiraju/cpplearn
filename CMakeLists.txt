

# CMakeList.txt : CMake project for latestcp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project ("cpplearn")

include_directories(include)


# Add source to this project's executable.
add_executable (cpplearn "src/main.cpp" )

