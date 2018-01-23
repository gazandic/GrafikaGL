cmake_minimum_required (VERSION 2.8.11)
project ("Plain_Triangle")

file(GLOB Sources "src/*.cpp")
add_executable ("Plain_Triangle" ${Sources})
