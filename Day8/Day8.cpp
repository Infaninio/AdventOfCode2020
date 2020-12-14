// Day1.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Day8.h"

using namespace std;

int main()
{
	auto instructions = readInstructions("../../../Day8/input.txt");

	int ip = 0;
	int acc = 0;

	
	
	//Part 1
	while (ip >= 0)
	{
		ip = executeInstruction(ip, instructions[ip], acc);
	}


	std::cout << "The Acc stays at (Part 1): " << acc << "\n";


	// Part 2
	// Brute force try and error
	resetInstructions(instructions);
	for (size_t i = 0; i < instructions.size(); i++)
	{
		auto newInstructionSet = instructions;
		
		
		if (Operation::ACC == instructions[i].op)
		{
			continue;
		}
		else
		{
			if (Operation::JMP == instructions[i].op)
			{
				newInstructionSet[i].op = Operation::NOP;
			}
			else if (Operation::NOP == instructions[i].op)
			{
				newInstructionSet[i].op = Operation::JMP;
			}
			else
			{
				std::cerr << "Unknown Instruction";
				return -1;
			}
		}


		//Execute new InstructionSet
		ip = 0;
		acc = 0;
		while (ip >= 0 && ip < newInstructionSet.size())
		{
			ip = executeInstruction(ip, newInstructionSet[ip], acc);
		}

		if (ip == newInstructionSet.size())
			break;
	}


	std::cout << "The Acc stays at (Part 2): " << acc << "\n";

}

std::vector<Instruction> readInstructions(std::string pathToFile)
{
	std::vector<Instruction> instructions;
	fstream file;
	file.open(pathToFile);
	string line;


	while (getline(file, line))
	{
		string inst = line.substr(0, 3);
		Instruction instruction;
		instruction.executed = false;

		if ("nop" == inst)
		{
			instruction.op = Operation::NOP;
		}
		else if ("acc" == inst)
		{
			instruction.op = Operation::ACC;
		}
		else if("jmp" == inst)
		{
			instruction.op = Operation::JMP;
		}

		instruction.value = stoi(line.substr(4));
		instructions.push_back(instruction);
	}

	
	
	return instructions;
}

int executeInstruction(int ip, Instruction& inst, int& accValue)
{
	if (inst.executed)
	{
		return -1;
	}


	switch (inst.op)
	{
	case Operation::ACC:
		accValue += inst.value;
		inst.executed = true;
		return ++ip;

	case Operation::NOP:
		inst.executed = true;
		return ++ip;

	case Operation::JMP:
		inst.executed = true;
		return (ip + inst.value);

	default:
		std::cerr << "Error unknown Instruction";
		return -1;
		break;
	}
	
	return 0;
}

void resetInstructions(std::vector<Instruction> &instructions)
{
	for (auto &inst : instructions)
	{
		inst.executed = false;
	}
}
