// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<int> getInput(std::string line);

void getClosestBus(std::vector<int>, size_t arrivalTime, int& busID, size_t& waitingTime);

size_t getCorrectBusArrival(std::vector<int> busList);