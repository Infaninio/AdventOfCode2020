// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day13.h"

using namespace std;

int main()
{
	fstream file;
	string line;
	file.open("../../../Day13/input.txt");
	int i = 0;
	size_t timeOfArrival;
	vector<int> busLines;

	while (getline(file,line))
	{
		if (0 == i)
		{
			timeOfArrival = stoll(line);
			i++;
		}
		else
		{
			busLines = getInput(line);
			i++;
		}
	}

	int busID;
	size_t waitingTime;
	getClosestBus(busLines, timeOfArrival, busID, waitingTime);

	cout << "The Bus ID * waitingTime gives (Part 1): " << busID * waitingTime << "\n";

	auto sol = getCorrectBusArrival(busLines);

	cout << "The perfect Bus Arrivale happens at (Part 2): " << sol << "\n";

}

std::vector<int> getInput(std::string line)
{
	vector<int> busLines;

	size_t pos = 0;

	while (pos < line.length())
	{
		auto tmp = line.substr(pos, line.find(',', pos) - pos);
		if (-1 == line.find(',', pos))
		{
			pos = line.length();
		}
		else
		{
			pos = line.find(',', pos) + 1;
		}
		
		if ("x" == tmp)
		{
			busLines.push_back(-1);
		}
		else
		{
			busLines.push_back(stoi(tmp));
		}


		
	}
	
	
	
	return busLines;
}

void getClosestBus(std::vector<int> busLines, size_t arrivalTime, int& busID, size_t& waitingTime)
{
	busID = 0;
	waitingTime = arrivalTime;

	for (auto busLine : busLines)
	{
		if (busLine == -1)
		{
			continue;
		}

		auto tmp = ceil(static_cast<double>(arrivalTime) / static_cast<double>(busLine));


		if (tmp*busLine > arrivalTime && (tmp * busLine - arrivalTime) < waitingTime)
		{
			waitingTime = tmp * busLine - arrivalTime;
			busID = busLine;
		}

	}



}

size_t getCorrectBusArrival(std::vector<int> busList)
{
	auto first = busList[0];
	vector<size_t> factors;
	int smallest = 9999;
	size_t smallestPos = 0;
	for (size_t i = 0; i < busList.size(); i++)
	{
		if (busList[i] < smallest)
		{
			smallest = busList[i];
			smallestPos = i;
		}
	}


	for (size_t i = 0; i < busList.size(); i++)
	{
		if (-1 == busList[i])
		{
			continue;
		}
			
		size_t factor = 0;
		size_t cnt = 1;
		while (1)
		{
			auto smallTimestamp = smallest * cnt;
			auto biggerTimestamp = smallTimestamp / busList[i];

			if (smallTimestamp * busList[i] == biggerTimestamp)
			{

			}


			cnt++;
		}
		

		factors.push_back(factor);

	}
	
	size_t solution = 1;

	for (auto fc : factors)
		solution *= fc;

	
	return solution;
}
