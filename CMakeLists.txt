# CMakeList.txt: CMake-Projektdatei der obersten Ebene. Führen Sie hier die globale Konfiguration aus,
# und schließen Sie Unterprojekte ein.
#
cmake_minimum_required (VERSION 3.8)

project ("AdventOfCode2020")

# Schließen Sie Unterprojekte ein.
add_subdirectory ("Day1")
add_subdirectory ("Day2")
