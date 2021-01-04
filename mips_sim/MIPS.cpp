#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>

#include "MIPS.h"

mips::mips()
{
    map_Rform();
    map_Iform();
}


std::string mips::find_inst(std::string &input)
{
    std::string inst;
    int i = 0;
    while (input[i] != ' ')
    {
        inst += input[i];
        ++i;
    }
    
    return inst;
}

void mips::parse_input(char *input, const int *MAX_BUF)
{
    std::string pseudo = cleanup(input, MAX_BUF);
    std::string op = find_inst(pseudo);

    std::map<std::string, int>::iterator it = RFormat_map.find(op);

    if (it != RFormat_map.end())
    {
       inst = new RForm(input, pseudo, it->second, r);
    }

    else input_error();

}


/*************************************************************************

	Basic input error detection

*************************************************************************/

void mips::input_error()
{
	std::cout << "Invalid input. Check your syntax. " << std::endl;
}


/*************************************************************************

	Removes whitespace from user input

*************************************************************************/

std::string cleanup(char *input, const int *MAX_BUF)
{
	std::string retval;
	int i = 0;
	while (i < *MAX_BUF && input[i] != '\0')
	{
		if (input[i] && !(input[i] == ' ' || input[i] == '\t'))
		{
            if (input[i] == '$') retval += " ";
			
            retval += input[i];
        }
		++i;
	}

	return retval;
}







/*************************************************************************

	Assigns each string input with its opcode for I-format instructions

*************************************************************************/

void mips::map_Iform()
{
	Iform_map.insert(std::make_pair("li", 1));
	//opcode_map.insert(std::make_pair("j", 2));
	//opcode_map.insert(std::make_pair("jal", 3));
	//opcode_map.insert(std::make_pair("beq", 4));
	//opcode_map.insert(std::make_pair("bne", 5));
	//opcode_map.insert(std::make_pair("blez", 6));
	//opcode_map.insert(std::make_pair("bgtz", 7));
	//opcode_map.insert(std::make_pair("addi", 8));
	//opcode_map.insert(std::make_pair("addiu", 9));
	//opcode_map.insert(std::make_pair("slti", 10));
	//opcode_map.insert(std::make_pair("sltiu", 11));
	//opcode_map.insert(std::make_pair("andi", 12));
	//opcode_map.insert(std::make_pair("ori", 13));
	//opcode_map.insert(std::make_pair("xori", 14));
	//opcode_map.insert(std::make_pair("lui", 15));
	//opcode_map.insert(std::make_pair("lb", 32));
	//opcode_map.insert(std::make_pair("lw", 35));
	//opcode_map.insert(std::make_pair("sb", 40));
	//opcode_map.insert(std::make_pair("sw", 43));
}


/*************************************************************************

	Assigns each string input with its function for R-format instructions

*************************************************************************/

void mips::map_Rform()
{
	//func_map.insert(std::make_pair("sll", 0));
	//func_map.insert(std::make_pair("srl", 2));
	//func_map.insert(std::make_pair("jr", 8));
	//func_map.insert(std::make_pair("mfhi", 16));
	//func_map.insert(std::make_pair("mflo", 18));
	//func_map.insert(std::make_pair("mult", 24));
	//func_map.insert(std::make_pair("multu", 25));
	//func_map.insert(std::make_pair("div", 26));
	//func_map.insert(std::make_pair("divu", 27));
	RFormat_map.insert(std::make_pair("add", 32));
	//func_map.insert(std::make_pair("addu", 33));
	//R_format_map.insert(std::make_pair("sub", 34));
	//func_map.insert(std::make_pair("subu", 35));
	//func_map.insert(std::make_pair("and", 36));
	//func_map.insert(std::make_pair("or", 37));
	//func_map.insert(std::make_pair("xor", 38));
	//func_map.insert(std::make_pair("nor", 39));
	//R_format_map.insert(std::make_pair("move", 40));
}
