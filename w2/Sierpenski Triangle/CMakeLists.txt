cmake_minimum_required (VERSION 2.8.11)
project ("Sierpenski_Triangle")

file(GLOB Sources "src/*.cpp")
add_executable ("Sierpenski_Triangle" ${Sources})
