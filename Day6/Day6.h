// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>




std::vector < std::map<char, int>> readInputDay6(std::string pathToFile);

std::map<char, int> getMapFromEntry(std::string entry, int numOfPeople);

