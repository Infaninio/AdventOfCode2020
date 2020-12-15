// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day11.h"

using namespace std;

int main()
{
	auto terminal = WaitingArea("../../../Day11/input.txt");

	terminal.simulatePeople(4);
	

	std::cout << terminal.getOccupied() << " Seats are occupied (Part 1) \n";


	terminal.reset();
	terminal.simulatePeople(5, true);
	terminal.printLayout();
	std::cout << terminal.getOccupied() << " Seats are occupied (Part 2) \n";
}

WaitingArea::WaitingArea(string pathToFile)
{
	fstream file;
	string line;

	file.open(pathToFile);
	this->FilePath = pathToFile;

	while (getline(file,line))
	{
		std::vector<SeatState> row;
		for (auto c : line)
		{
			switch (c)
			{
			case 'L':
				row.push_back(SeatState::Empty);
				break;
			case '.':
				row.push_back(SeatState::Floor);
				break;
			case '#':
				row.push_back(SeatState::Occupied);
				break;
			default:
				std::cerr << "Fehler Char in Input File unknown";
				return;
				break;
			}
		}

		this->layout.push_back(row);
	}


	file.close();
}

size_t WaitingArea::getOccupied()
{
	size_t cnt=0;

	for (auto x : this->layout)
	{
		for (auto y : x)
		{
			if (SeatState::Occupied == y)
				cnt++;
		}
	}
	
	return cnt;
}

size_t WaitingArea::getEmpty()
{
	size_t cnt = 0;

	for (auto x : this->layout)
	{
		for (auto y : x)
		{
			if (SeatState::Empty == y)
				cnt++;
		}
	}

	return cnt;
}

void WaitingArea::simulatePeople(const int maxNeighbors, bool V2)
{
	auto newLayout = this->layout;


	while (1)
	{
		for (size_t y = 0; y < this->layout.size(); y++)
		{
			for (size_t x = 0; x < this->layout[y].size(); x++)
			{
				
				switch (getSeatState(x,y))
				{
				case SeatState::Floor:
					continue;
				
				case SeatState::Empty:
					if (getNumberofOccupiedNeighbors(x,y, V2) == 0)
						newLayout[y][x] = SeatState::Occupied;
					else
						newLayout[y][x] = this->layout[y][x];
					
					break;

				case SeatState::Occupied:
					if (getNumberofOccupiedNeighbors(x,y, V2) >= maxNeighbors)
						newLayout[y][x] = SeatState::Empty;
					else
						newLayout[y][x] = this->layout[y][x];
					
					break;

				default:
					break;
				}
			}
		}

		if (newLayout == this->layout)
		{
			return;
		}
		
		this->layout = newLayout;
	}


}

void WaitingArea::printLayout()
{
	cout << "\n";
	for (auto i : this->layout)
	{
		for (auto j : i)
			cout << j;

		cout << "\n";
	}
	cout << "\n";
}

void WaitingArea::reset(std::string pathToFile)
{
	fstream file;
	string line;

	
	

	this->layout.clear();
	
	if (pathToFile.empty())
	{
		pathToFile = this->FilePath;
	}
	else
	{
		this->FilePath = pathToFile;
	}


	file.open(pathToFile);
	while (getline(file, line))
	{
		std::vector<SeatState> row;
		for (auto c : line)
		{
			switch (c)
			{
			case 'L':
				row.push_back(SeatState::Empty);
				break;
			case '.':
				row.push_back(SeatState::Floor);
				break;
			case '#':
				row.push_back(SeatState::Occupied);
				break;
			default:
				std::cerr << "Fehler Char in Input File unknown";
				return;
				break;
			}
		}

		this->layout.push_back(row);
	}


	file.close();
}

int WaitingArea::getNumberofOccupiedNeighbors(size_t x, size_t y, bool V2)
{
	int occupied = 0;

	for (int i = int(x)-1; i <= int(x)+1; i++)
	{
		for (int j = int(y) - 1; j <= int(y) + 1; j++)
		{
			if (SeatState::Occupied == getSeatState(i, j) && !(x==i && y==j))
				occupied++;
			else if(V2 && !(x == i && y == j))
			{
				int cnt = 0;
				int newI = i;
				int newJ = j;
				while (SeatState::Floor == getSeatState(newI,newJ))
				{
					cnt++;
					newI =i- cnt * (x - i);
					newJ =j- cnt * (y - j);
				}

				if (SeatState::Occupied == getSeatState(newI, newJ) && !(x == (newI) && y == (newJ)))
					occupied++;
			}
		}
	}
	
	
	return occupied;
}

SeatState WaitingArea::getSeatState(int x, int y)
{
	if (x >= this->layout[0].size() || x < 0)
	{
		return SeatState::OutOfRange;
	}
	if (y >= this->layout.size() || y < 0)
	{
		return SeatState::OutOfRange;
	}


	return this->layout[y][x];
}
