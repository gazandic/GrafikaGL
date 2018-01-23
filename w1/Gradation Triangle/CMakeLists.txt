cmake_minimum_required (VERSION 2.8.11)
project ("Gradation_Triangle")

file(GLOB Sources "src/*.cpp")
add_executable ("Gradation_Triangle" ${Sources})
