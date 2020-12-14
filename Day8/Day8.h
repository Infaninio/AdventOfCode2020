// Day1.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


enum Operation
{
	ACC,
	JMP,
	NOP,
};



struct Instruction
{
	Operation op;
	int value;
	bool executed;

};


std::vector<Instruction> readInstructions(std::string pathToFile);

int executeInstruction(int ip, Instruction& inst, int& accValue);

void resetInstructions(std::vector<Instruction> &inst);