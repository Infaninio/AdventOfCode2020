// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


std::vector<std::vector<bool>> readInput(std::string pathToFile);

inline size_t traverseMap(std::vector<std::vector<bool>> input, int slopeR, int slopeD);


// TODO: Verweisen Sie hier auf zusätzliche Header, die Ihr Programm erfordert.
