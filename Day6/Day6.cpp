// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day6.h"

using namespace std;

int main()
{
	auto groups = readInputDay6("../../../Day6/input.txt");

	size_t yesAnswers=0;
	for (auto group : groups)
	{
		yesAnswers += group.size() - 1;
	}
	std::cout << "Number of Yes Answers in Group (Part 1): " << yesAnswers << "\n";

	yesAnswers = 0;



	for (auto group : groups)
	{
		int numOfMembers = group['#'];
		for (auto yes : group)
		{
			if (yes.first != '#')
			{
				if (yes.second == numOfMembers)
					yesAnswers += 1;
			}
		}
	}

	std::cout << "Number of Yes Answers of everyone in a group (Part 2): " << yesAnswers << "\n";
}

std::vector<std::map<char, int>> readInputDay6(std::string pathToFile)
{
	std::fstream file;
	file.open(pathToFile);
	std::string line, entry;
	int entryCnt = 0;
	std::vector<std::map<char, int>> input;

	while (getline(file, line))
	{
		if (line.empty())
		{
			input.push_back(getMapFromEntry(entry, entryCnt));
			entry = "";
			entryCnt = 0;
		}
		else
		{
			entry = entry + line;
			entryCnt++;
		}
	}

	if (!entry.empty())
	{
		input.push_back(getMapFromEntry(entry, entryCnt));
	}

	return input;
}

std::map<char, int> getMapFromEntry(std::string entry, int numOfPeople)
{
	std::map<char, int> group;

	group['#'] = numOfPeople;

	for (auto c : entry)
	{
		if (group.find(c) == group.end())
		{
			group[c] = 1;
		}
		else
		{
			group[c] += 1;
		}
	}
	
	return group;
}
