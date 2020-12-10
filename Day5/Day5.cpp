// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day5.h"

using namespace std;

int main()
{
	//std::cout << "Test: \n";
	//std::cout << getSeatID("BFFFBBFRRR") << "\n" << getSeatID("FFFBBBFRRR") << "\n" << getSeatID("BBFFBBFRLL");


	//Part 1
	size_t highestID = 0;

	for (auto boardingpass : input)
	{
		if (getSeatID(boardingpass) > highestID)
			highestID = getSeatID(boardingpass);
	}

	std::cout << "Highest SeatID (Part 1) is: " << highestID;

	//Part 2
	std::vector<int> usedSeatIds;
	for (auto bp : input)
	{
		usedSeatIds.push_back(getSeatID(bp));
	}

	sort(usedSeatIds.begin(), usedSeatIds.end());

	for (size_t i = 0; i < usedSeatIds.size(); i++)
	{
		if (usedSeatIds[i] == (usedSeatIds[i+1] -2))
		{
			std::cout << "My Seat is: " << (usedSeatIds[i] + 1) << endl;
			return 0;
		}
	}

}

int getSeatID(string code)
{
	int seatId = 0;
	for (int i = 0; i < code.length(); i++)
	{
		if ('R' == code[code.length() - i - 1] || 'B' == code[code.length() - i - 1])
			seatId += pow(2, i);
	}

	return seatId;
}