// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


enum Movements
{
	North,
	East,
	South,
	West,
	LeftTurn,
	RightTurn,
	Forward,
};

struct Position
{
	int x;
	int y;

	Position(int xi, int yi) :
		x{ xi },
		y{ yi } {};
};


std::vector<std::pair<Movements, int>> getInstructions(std::string pathToFile);


class Ship
{
public:
	Ship(Movements startDir = Movements::East) :
		facing{ startDir },
		startPos{ Position(0, 0) },
		currentPos{ Position(0,0) },
		wayPoint{ Position(10,1) }{};

	void move(std::pair<Movements, int> move);
	void move(std::vector<std::pair<Movements, int>>);
	void moveWithWaypoint(std::vector<std::pair<Movements, int>>);
	void moveWaypoint(std::pair<Movements, int> move);
	size_t getManhattenDistance();
	void reset();

private:
	Movements facing;
	Position startPos;
	Position currentPos;
	Position wayPoint;

};

