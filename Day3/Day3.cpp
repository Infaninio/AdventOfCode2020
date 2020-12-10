// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day3.h"

using namespace std;

int main()
{
	auto input = readInput("../../../Day3/input.txt");

	// Part 1
	std::cout << "Number of Trees (Part1): " << traverseMap(input,3,1) << "\n";


	auto trees = traverseMap(input, 1, 1);
	trees *= traverseMap(input, 3, 1);
	trees *= traverseMap(input, 5, 1);
	trees *= traverseMap(input, 7, 1);
	trees *= traverseMap(input, 1, 2);

	std::cout << "Number of Trees (Part2): " << trees << "\n";
}



std::vector<std::vector<bool>> readInput(std::string pathToFile)
{
	std::vector<vector<bool>> input;

	ifstream file;
	file.open(pathToFile);

	string line;

	while (getline(file, line))
	{
		vector<bool> treeLine;

		for (auto c : line)
		{
			if ('#' == c)
				treeLine.push_back(true);
			else
				treeLine.push_back(false);
		}
		

		input.push_back(treeLine);
	}
	return input;
}

size_t traverseMap(std::vector<std::vector<bool>> input, int slopeR, int slopeD)
{
	auto numOfCols = input[0].size();
	auto numOfRows = input.size();

	size_t rowPos = 0;
	size_t colPos = 0;

	size_t numOfTrees = 0;



	while (rowPos < numOfRows)
	{
		//Increase to next Pos
		if (colPos >= numOfCols)
			colPos %= numOfCols;

		if (input[rowPos][colPos])
			numOfTrees++;

		rowPos += slopeD;
		colPos += slopeR;
	}

	return numOfTrees;
}
