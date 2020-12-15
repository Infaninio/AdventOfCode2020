// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day12.h"

using namespace std;

int main()
{
	auto ship = Ship();
	auto instr = getInstructions("../../../Day12/input.txt");
	ship.move(instr);


	std::cout << "The Manhatten distance is (Part 1): " << ship.getManhattenDistance() << "\n";


	ship.reset();
	ship.moveWithWaypoint(instr);

	std::cout << "The Manhatten distance is (Part 2): " << ship.getManhattenDistance() << "\n";
}

void Ship::move(std::pair<Movements, int> move)
{
	if (Movements::Forward == move.first)
	{
		move.first = this->facing;
	}
	
	
	
	switch (move.first)
	{
	case Movements::LeftTurn:
		move.second = 360 - move.second;
		facing = Movements((facing + move.second / 90) % 4);
		break;
	case Movements::RightTurn:
		facing = Movements((facing + move.second / 90) % 4);
		break;
	case Movements::North:
		this->currentPos.y += move.second;
		break;
	case Movements::South:
		this->currentPos.y -= move.second;
		break;
	case Movements::East:
		this->currentPos.x += move.second;
		break;
	case Movements::West:
		this->currentPos.x -= move.second;
	default:
		break;
	}




}

void Ship::move(std::vector<std::pair<Movements, int>> instructions)
{
	for (auto inst : instructions)
		move(inst);
}

void Ship::moveWithWaypoint(std::vector<std::pair<Movements, int>> instructions )
{
	for (auto i : instructions)
		moveWaypoint(i);
}

void Ship::moveWaypoint(std::pair<Movements, int> move)
{
	if (Movements::Forward == move.first)
	{
		currentPos.x += move.second * wayPoint.x;
		currentPos.y += move.second * wayPoint.y;
	}


	auto oldPos = this->wayPoint;
	switch (move.first)
	{
	case Movements::LeftTurn:
		//move.second = 360 - move.second;
		for (size_t i = 0; i < (move.second / 90); i++)
		{
			oldPos = this->wayPoint;
			this->wayPoint.x = oldPos.y * -1;
			this->wayPoint.y = oldPos.x;
		}
		break;
	
	case Movements::RightTurn:
		for (size_t i = 0; i < (move.second / 90); i++)
		{
			oldPos = this->wayPoint;
			this->wayPoint.x = oldPos.y;
			this->wayPoint.y = oldPos.x * - 1;
		}
		break;
	case Movements::North:
		this->wayPoint.y += move.second;
		break;
	case Movements::South:
		this->wayPoint.y -= move.second;
		break;
	case Movements::East:
		this->wayPoint.x += move.second;
		break;
	case Movements::West:
		this->wayPoint.x -= move.second;
	default:
		break;
	}
}

size_t Ship::getManhattenDistance()
{
	return abs(currentPos.x) + abs(currentPos.y);
}

void Ship::reset()
{
	this->startPos.x = 0;
	this->startPos.y = 0;
	this->currentPos.x = 0;
	this->currentPos.y = 0;
	this->wayPoint = Position(10, 1);
	this->facing = Movements::East;
}

std::vector<std::pair<Movements, int>> getInstructions(std::string pathToFile)
{
	std::vector<std::pair<Movements, int>> movements;
	fstream file;
	string line;
	file.open(pathToFile);

	while (getline(file, line))
	{
		std::pair<Movements, int> movement;
		switch (line[0])
		{
		case 'N':
			movement.first = Movements::North;
			break;
		case 'S':
			movement.first = Movements::South;
			break;
		case 'E':
			movement.first = Movements::East;
			break;
		case 'W':
			movement.first = Movements::West;
			break;
		case 'L':
			movement.first = Movements::LeftTurn;
			break;
		case 'R':
			movement.first = Movements::RightTurn;
			break;
		case 'F':
			movement.first = Movements::Forward;
			break;
		default:
			std::cerr << "Unknown movement";
			break;
		}

		movement.second = stoi(line.substr(1));

		movements.push_back(movement);
	}




	return movements;
}
