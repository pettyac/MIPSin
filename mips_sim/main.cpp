// Author: Adam Petty

#include <iostream>
#include <limits>
#include <bitset>
#include <fstream>
#include <iterator>
#include <fstream>

#include "RegFile.h"
#include "MIPS.h"
#include "convert.h"

const int MAX_BUF = 1024;

void read_from_file(char*);
void interpreter_mode();


int main(int argc, char* argv[])
{
	std::cout << argv[1] << std::endl;
	
	if (*(argv[1]) == 'R')
	{
		read_from_file(argv[2]);
	}

	else if (*(argv[1]) == 'U')
	{
		std::cout << "interpreter mode " << argv[1] << std::endl;
		interpreter_mode();
	}
	std::cout << "Enter " << std::endl;
	return 0;
}

void read_from_file(char* filename)
{
	std::ifstream file(filename, std::ios::in);
	std::string line;
	mips m;
	while (!file.eof())	
	{
		getline(file, line);
		std::cout << line << std::endl;
		line = m.parse_input(line);
		Inst* obj = m.create_inst(line);
		std::cout << *obj << std::endl;
		m.add_inst_to_mem(obj);
		m.execute_inst();
		delete obj;

		std::cout << m.r << std::endl;
	}
}

void interpreter_mode()
{
	mips m;
	char input[MAX_BUF];
	std::string inst_input;
	int inst;
    while(1)
	{
        std::cout << ">>> ";
		std::cin.getline(input, MAX_BUF);
		if (std::cin.eof()) break;
		if (std::cin.fail() || std::cin.bad())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		
		inst_input = m.parse_input(input);
		Inst* obj = m.create_inst(inst_input);
		std::cout << *obj << std::endl;
		m.add_inst_to_mem(obj);
		m.execute_inst();
		delete obj;

		std::cout << m.r << std::endl;
	}    
}


 
