cmake_minimum_required (VERSION 2.8.11)
project ("Sierpinski_Point")

file(GLOB Sources "src/*.cpp")
add_executable ("Sierpinski_Point" ${Sources})
