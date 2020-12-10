// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day4.h"

using namespace std;

int main()
{
	auto passports = readBatch("../../../Day4/input.txt");

	size_t validPassports=0;

	for (auto pp : passports)
	{
		if (pp.isValid)
			validPassports++;
	}

	cout << validPassports << " Passports are valid (Part 1)\n";


	//Check th passports again Part2
	validPassports = 0;


	for (auto &pp : passports)
		validatePassort(pp);

	for (auto pp : passports)
	{
		if (pp.isValid)
			validPassports++;
	}

	cout << validPassports << " Passports are valid (Part 2)\n";
}

std::vector<Passport> readBatch(std::string pathToFile)
{
	std::vector<Passport> passports;
	
	ifstream file;
	file.open(pathToFile);
	string line;
	string entry;

	while (getline(file, line))
	{
		if (line.empty())
		{
			passports.push_back(getPassportFromEntry(entry));
			entry.clear();
		}
		else
		{
			entry = entry + " " + line;
		}
	}

	if (!entry.empty())
	{
		passports.push_back(getPassportFromEntry(entry));
	}

	return passports;
}

Passport getPassportFromEntry(std::string entry)
{
	std::string byr;
	std::string iyr;
	std::string eyr;
	std::string hgt;
	std::string hcl;
	std::string ecl;
	std::string pid;
	std::string cid;
	bool isValid = true;

	auto pos = entry.find("byr:");
	if (pos == string::npos)
	{
		isValid = false;
	}
	else
	{
		auto pos2 = entry.find(" ", pos);
		pos += 4;
		byr = entry.substr(pos, pos2 - pos);
	}
	
	
	pos = entry.find("iyr:");
	if (pos == string::npos)
	{
		isValid = false;
	}
	else
	{
		auto pos2 = entry.find(" ", pos);
		pos += 4;
		iyr = entry.substr(pos, pos2 - pos);
	}

	pos = entry.find("eyr:");
	if (pos == string::npos)
	{
		isValid = false;
	}
	else
	{
		auto pos2 = entry.find(" ", pos);
		pos += 4;
		eyr = entry.substr(pos, pos2 - pos);
	}

	pos = entry.find("hgt:");
	if (pos == string::npos)
	{
		isValid = false;
	}
	else
	{
		auto pos2 = entry.find(" ", pos);
		pos += 4;
		hgt = entry.substr(pos, pos2 - pos);
	}

	pos = entry.find("hcl:");
	if (pos == string::npos)
	{
		isValid = false;
	}
	else
	{
		auto pos2 = entry.find(" ", pos);
		pos += 4;
		hcl = entry.substr(pos, pos2 - pos);
	}

	pos = entry.find("ecl:");
	if (pos == string::npos)
	{
		isValid = false;
	}
	else
	{
		auto pos2 = entry.find(" ", pos);
		pos += 4;
		ecl = entry.substr(pos, pos2 - pos);
	}

	pos = entry.find("pid:");
	if (pos == string::npos)
	{
		isValid = false;
	}
	else
	{
		auto pos2 = entry.find(" ", pos);
		pos += 4;
		pid = entry.substr(pos, pos2 - pos);
	}

	pos = entry.find("cid:");
	if (pos == string::npos)
	{
		//isValid = false;
	}
	else
	{
		auto pos2 = entry.find(" ", pos);
		pos += 4;
		cid = entry.substr(pos, pos2 - pos);
	}

	return Passport(byr,iyr,eyr,hgt,hcl,ecl,pid,cid,isValid);
}

void validatePassort(Passport& passport)
{
	if (!(passport.isValid))
	{
		return;
	}

	//Birth Year
	auto nmb = stoi(passport.byr);
	if (nmb > 2002 || nmb < 1920)
	{
		passport.isValid = false;
		return;
	}

	// Issue Year
	nmb = stoi(passport.iyr);
	if (nmb > 2020 || nmb < 2010)
	{
		passport.isValid = false;
		return;
	}

	// Expiration Year
	nmb = stoi(passport.eyr);
	if (nmb > 2030 || nmb < 2020)
	{
		passport.isValid = false;
		return;
	}


	// Height
	if (!(string::npos == passport.hgt.find("cm")))
	{
		nmb = stoi(passport.hgt.substr(0, passport.hgt.length() - 2));
		if (nmb > 193 || nmb < 150)
		{
			passport.isValid = false;
			return;
		}
	}
	else if (!(string::npos == passport.hgt.find("in")))
	{
		nmb = stoi(passport.hgt.substr(0, passport.hgt.length() - 2));
		if (nmb > 76 || nmb < 59)
		{
			passport.isValid = false;
				return;
		}
	}
	else
	{
		passport.isValid = false;
		return;
	}



	//Hair Color
	if ('#' == passport.hcl[0] && 7 == passport.hcl.length())
	{
		if (!(passport.hcl.find_first_not_of("0123456789abcdef", 1) == string::npos))
		{
			passport.isValid = false;
			return;
		}
	}
	else
	{
		passport.isValid = false;
		return;
	}

	//Passport ID
	if (!((9 == passport.pid.length()) && is_number(passport.pid)))
	{
		passport.isValid = false;
		return;
	}

	//Eye Color
	if (string::npos != passport.ecl.find("amb"))
		return;

	if (string::npos != passport.ecl.find("blu"))
		return;

	if (string::npos != passport.ecl.find("brn"))
		return;
	
	if (string::npos != passport.ecl.find("gry"))
		return;
	
	if (string::npos != passport.ecl.find("grn"))
		return;
	
	if (string::npos != passport.ecl.find("hzl"))
		return;
	
	if (string::npos != passport.ecl.find("oth"))
		return;


	passport.isValid = false;
	return;
	


}



bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
