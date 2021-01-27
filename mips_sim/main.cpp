// File: a03q06.cpp
// Author: Adam Petty

#include <iostream>
#include <limits>
#include <bitset>

#include "RegFile.h"
#include "MIPS.h"
#include "convert.h"

const int MAX_BUF = 1024;

int main()
{
    mips m;
	char input[MAX_BUF];
	std::string pseudo_inst;
    std::string op;
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
		
		m.parse_input(input, &MAX_BUF);
        inst = m.fetch(m.PC());
    /*    
 
        std::cout << *(inst) << std::endl;     
    
		if (it != m.opcode_map.end())
		{
			inst = m.input_to_IForm(input, &MAX_BUF);
			if(inst != "ERROR")
			{
				m.I_table();
			}
		}
		else 
		{
			it = m.func_map.find(inst);
			if (it != m.func_map.end())
			{
				inst = m.input_to_RForm(input, &MAX_BUF);
				if(inst != "ERROR")
				{
					m.R_table();
				}
			}
		}
    */    
    }
    
	return 0;
}



 
