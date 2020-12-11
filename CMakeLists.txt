# CMakeList.txt: CMake-Projektdatei der obersten Ebene. Führen Sie hier die globale Konfiguration aus,
# und schließen Sie Unterprojekte ein.
#
cmake_minimum_required (VERSION 3.8)

project ("AdventOfCode2020")

# Schließen Sie Unterprojekte ein.
add_subdirectory ("Day1")
add_subdirectory ("Day2")
add_subdirectory ("Day3")
add_subdirectory ("Day4")
add_subdirectory ("Day5")
add_subdirectory ("Day6")