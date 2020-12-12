// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day7.h"

using namespace std;

int main()
{
	auto rules = getRules("../../../Day7/input.txt");

	std::set<std::string> containedIn;


	isContainedIn("shiny gold", rules, containedIn);

	std::cout << "\n" << containedIn.size() << " different Bags can contain a shiny gold bag (Part 1)\n";



	//Part 2
	auto cnt = contains("shiny gold", rules);



	std::cout << "The shiny gold bag includes " << cnt << " other bags\n";


}



std::map<std::string, std::map <std::string, int>> getRules(std::string pathToFile)
{
	std::map<std::string, std::map <std::string, int>> rules;
	std::string line;


	std::fstream file;
	file.open(pathToFile);


	while (getline(file, line))
	{
		std::map <std::string, int> rule;
		auto words = stringToWords(line);


		// Sourt out Empty lines. Schould not occure
		if (words.empty())
			continue;



		// Get the Name of the bag and check if it contains any more bags
		std::string bagColor, newBag;
		int i = 0;
		bagColor = words[0] + " " + words[1];
		rules[bagColor];
		if ("no" == words[4])
			continue;



		//Check all contained bags until we reach the end of the line
		int pos = 4;
		while (pos < words.size())
		{
			std::string bagname = words[pos + 1] + " " + words[pos + 2];
			int numberOfBags = stoi(words[pos]);
			rule[bagname] = numberOfBags;
			pos += 4;
		}

		rules[bagColor] = rule;
	}



	return rules;
}

std::vector<std::string> stringToWords(std::string line)
{
	std::vector<std::string> words;

	std::string word;

	for (auto c : line)
	{
		if (' ' == c)
		{
			words.push_back(word);
			word = "";
		}
		else
		{
			word.push_back(c);
		}
	}

	if (!word.empty())
		words.push_back(word);


	return words;
}


size_t contains(std::string color, std::map<std::string, std::map<std::string, int>>& rules, bool firstCall)
{
	size_t cnt=1;

	for (auto bag : rules[color])
	{
		cnt += bag.second * contains(bag.first, rules, false);
	}
	
	
	return firstCall ? (cnt-1) : cnt;

}

void isContainedIn(std::string color, const std::map<std::string, std::map<std::string, int>>& rules, std::set<std::string>& container)
{
	for (auto rule : rules)
	{

		for (auto bag : rule.second)
		{
			if (color == bag.first)
			{
				container.emplace(rule.first);
				isContainedIn(rule.first, rules, container);
				break;
			}
		}


	}



}


