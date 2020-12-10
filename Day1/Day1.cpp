// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day1.h"

using namespace std;

int main()
{
	// Aufgabe 1
	//for (auto var : input)
	//{
	//	for (auto var2 : input)
	//	{
	//		if (2020 == (var+var2))
	//		{
	//			std::cout << "Die Loesung ist: " << (var * var2) << "\n";
	//			return 0;
	//		}
	//	}
	//}


	//Part2
	for (auto var : input)
	{
		for (auto var2 : input)
		{
			for (auto var3 : input)
			{
				if (2020 == (var+var2+var3))
				{
					std::cout << "Solution Part2: " << (var * var2 * var3) << "\n";
					return 0;
				}
			}
		}
	}

	return 0;
}
