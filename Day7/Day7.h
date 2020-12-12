// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>



std::map < std::string, std::map <std::string, int>> getRules(std::string pathToFile);

std::vector<std::string> stringToWords(std::string line);


size_t contains(std::string color, std::map<std::string, std::map <std::string, int>> &rules, bool firstCall=true);

void isContainedIn(std::string color, const std::map<std::string, std::map <std::string, int>> &rules, std::set<std::string>& container);