cmake_minimum_required (VERSION 2.8.11)
project (GrafikaGL)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/include)
set(CMAKE_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

# Add link dependencies recursively
macro (add_executable _name)
    # invoke built-in add_executable
    _add_executable(${ARGV})
    if (TARGET ${_name})
		target_link_libraries (${_name} ${CMAKE_THREAD_LIBS_INIT})
    endif()
endmacro()

add_subdirectory (w1)
add_subdirectory (w2)