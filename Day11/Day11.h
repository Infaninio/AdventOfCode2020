// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


enum SeatState
{
	Floor,
	Empty,
	Occupied,
	OutOfRange,
};



class WaitingArea
{
public:
	WaitingArea(std::string pathToFile);
	size_t getOccupied();
	size_t getEmpty();
	void simulatePeople(const int maxNeighbors, bool V2=false);
	void printLayout();
	void reset(std::string pathToFile = "");


private:
	std::vector<std::vector<SeatState>> layout;
	int getNumberofOccupiedNeighbors(size_t x, size_t y, bool V2);
	inline SeatState getSeatState(int x, int y);
	std::string FilePath;
};



