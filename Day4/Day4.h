// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Passport
{
	std::string byr;
	std::string iyr;
	std::string eyr;
	std::string hgt;
	std::string hcl;
	std::string ecl;
	std::string pid;
	std::string cid;
	bool isValid;

	Passport(std::string byr, std::string iyr, std::string eyr, std::string hgt, std::string hcl, std::string ecl, std::string pid, std::string cid, bool valid)
		: byr(byr)
		, iyr(iyr)
		, eyr(eyr)
		, hgt(hgt)
		, hcl(hcl)
		, ecl(ecl)
		, pid(pid)
		, cid(cid)
		, isValid(valid) {}
};



std::vector<Passport> readBatch(std::string pathToFile);

Passport getPassportFromEntry(std::string entry);

void validatePassort(Passport& passport);

inline bool is_number(const std::string& s);

// TODO: Verweisen Sie hier auf zusätzliche Header, die Ihr Programm erfordert.
