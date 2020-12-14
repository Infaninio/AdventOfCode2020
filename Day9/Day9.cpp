// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day9.h"

using namespace std;

int main()
{
	auto numbers = readNumbers("../../../Day9/input.txt");

	auto firstError = getfirstIncorrect(numbers, 25);

	cout << "The first incorrect Number (Part 1) is: " << firstError << "\n";

	auto contiguesList = findContiguesList(numbers, firstError);

	size_t smallest, biggest;
	biggest = 0;
	smallest = numeric_limits<size_t>::max();

	for (auto i : contiguesList)
	{
		if (i > biggest)
		{
			biggest = i;
		}
		if (i < smallest)
		{
			smallest = i;
		}
	}



	cout << "The weakness (Part 2) is: " << (smallest + biggest) << "\n";
}

std::vector<size_t> readNumbers(std::string pathToFile)
{
	vector<size_t> numbers;
	string line;
	fstream file;
	file.open(pathToFile);

	while (getline(file, line))
	{
		numbers.push_back(stoll(line));
	}

	return numbers;
}

size_t getfirstIncorrect(std::vector<size_t> numbers, int preambleLength)
{
	
	for (size_t i = preambleLength; i < numbers.size(); i++)
	{
		vector<size_t>::const_iterator startIt = numbers.begin() + i - preambleLength;
		vector<size_t>::const_iterator endIT = numbers.begin() + i;

		vector<size_t> possibleNumbers(startIt, endIT);

		if (!canBeBuildOf(numbers[i], possibleNumbers))
		{
			return numbers[i];
		}

	}
	
	
	return -1;
}

bool canBeBuildOf(size_t number, std::vector<size_t> numbers)
{
	for (size_t i = 0; i < numbers.size(); i++)
	{
		for (size_t j = 0; j < numbers.size(); j++)
		{
			if (((numbers[i] + numbers[j]) == number) && i != j )
			{
				return true;
			}
		}
	}
	
	return false;
}

std::vector<size_t> findContiguesList(std::vector<size_t> list, int number)
{
	std::vector<size_t> newList;
	
	
	for (size_t i = 0; i < list.size(); i++)
	{
		newList.clear();

		newList.push_back(list[i]);

		auto j = i + 1;

		for (size_t j = i+1; j < list.size(); j++)
		{
			newList.push_back(list[j]);

			if (sumOfList(newList) == number)
			{
				return newList;
			}
			else if (sumOfList(newList) > number)
			{
				break;
			}

		}
	}
	
	return std::vector<size_t>();
}

size_t sumOfList(std::vector<size_t> list)
{
	size_t sum=0;

	for (auto i : list)
		sum += i;
	
	
	return sum;
}
