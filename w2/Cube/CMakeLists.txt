cmake_minimum_required (VERSION 2.8.11)
project ("Cube")

file(GLOB Sources "src/*.cpp")
add_executable ("Cube" ${Sources})
