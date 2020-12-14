// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>


std::vector<int> getAdapters(std::string pathToFile);

std::map<int, int> getJoltDifferences(std::vector<int> adapters);

size_t adapterCombinations(std::vector<int> adapters, size_t posInArray=0);