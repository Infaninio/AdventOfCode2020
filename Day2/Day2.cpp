// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day2.h"

using namespace std;

int main()
{
	int correctPW = 0;
	
	
	// Part 1
	/*for (auto var : input)
	{
		int numOfChar = 0;
		for each (auto letter in var.password)
		{
			if (var.letter == letter)
				numOfChar++;
		}

		if (numOfChar >= var.minNumOfAppearance && numOfChar <= var.maxNumOfAppeareance)
			correctPW++;

	}*/


	//Part 2
	for (auto pwContainer : input)
	{
		if (!(pwContainer.letter == pwContainer.password.at(pwContainer.minNumOfAppearance - 1)) != !(pwContainer.letter == pwContainer.password.at(pwContainer.maxNumOfAppeareance - 1)))
			correctPW++;
	}


	std::cout << correctPW << " correct Passwords";
}
