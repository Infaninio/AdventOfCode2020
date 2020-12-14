// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day10.h"

using namespace std;

int main()
{
	auto adapters = getAdapters("../../../Day10/input.txt");
	sort(adapters.begin(), adapters.end());
	auto numOfDifferences = getJoltDifferences(adapters);

	std::cout << "Multiplied number of 1-Jolt and 3-Jolt differences (Part 1): " << (numOfDifferences[1] * numOfDifferences[3]) << "\n";


	std::cout << "All possible Adapter Combinations: " << adapterCombinations(adapters) << "\n";

}

std::vector<int> getAdapters(std::string pathToFile)
{
	vector<int> adapters;
	fstream file;
	string line;

	file.open(pathToFile);

	adapters.push_back(0);
	int max = 0;

	while (getline(file,line))
	{
		auto value = stoi(line);
		adapters.push_back(value);
		if (value > max)
		{
			max = value;
		}
	}
	
	adapters.push_back(max+3);
	
	return adapters;
}

std::map<int, int> getJoltDifferences(std::vector<int> adapters)
{
	std::map<int, int> differences;
	
	for (size_t i = 0; i < adapters.size() - 1; i++)
	{
		auto diff = adapters[i + 1] - adapters[i];

		differences[diff] += 1;
	}
	
	
	
	return differences;
}

size_t adapterCombinations(std::vector<int> adapters, size_t posInArray)
{
	size_t counter = 0;

	//sort(adapters.begin(), adapters.end());


	for (size_t i = posInArray+1; i < adapters.size(); i++)
	{
		if (adapters[i] <= adapters[posInArray] + 3 )
		{
			counter += adapterCombinations(adapters, i);
		}
		else
		{
			break;
		}
	}

	if (posInArray +1 == adapters.size())
	{
		counter = 1;
	}

	
	
	return counter;
}


