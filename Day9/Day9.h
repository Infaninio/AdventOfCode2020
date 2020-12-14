// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>




std::vector<size_t> readNumbers(std::string pathToFile);

size_t getfirstIncorrect(std::vector<size_t> numbers, int preambleLength);

bool canBeBuildOf(size_t number, std::vector<size_t> numbers);

std::vector<size_t> findContiguesList(std::vector<size_t> list, int number);

size_t sumOfList(std::vector<size_t> list);

