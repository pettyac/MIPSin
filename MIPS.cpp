#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>

#include "MIPS.h"


/*************************************************************************
    
    default const
    -populates the R and I format instruction maps

*************************************************************************/

mips::mips()
    : _PC(0)
{
    assign_RFormat();
    assign_IFormat();
    std::cout << "CONSTRUCT" << std::endl;
}


/*************************************************************************
    
    parse_input(char, const int)
    -reads the instruction from the input

*************************************************************************/

void mips::parse_input(char *in, const int *MAX_BUF)
{
    std::string input = cleanup(in, MAX_BUF);   // remove whitespace
    std::string op = find_inst(input);             // isolates the inst

    if (isRFormat(op))
    {
        input_to_RForm(input, op);
    }
    else if (isIFormat(op))
    {
        input_to_IForm(input, op);
    }
    else input_error();

}


/*************************************************************************
    
    find_inst(string)
    -

*************************************************************************/

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


int mips::fetch(int pc)
{
    std::map<unsigned long int, Inst*>::iterator it = mem.find(pc);
    if (it != mem.end())
    {
        _PC++;
        int* x = mem[pc]->dec_inst();
        std::cout << x << std::endl;
        std::cout << *x << std::endl;
    }
    
    return 0;

}

/*************************************************************************
    
    isRFormat(string)
    -return true if inst is a R-Format inst

*************************************************************************/

bool mips::isRFormat(std::string &op)
{
    std::map<std::string, int>::iterator it = RFormat_map.find(op);
    
    if (it != RFormat_map.end()) return true;
    else return false;
}


/*************************************************************************
    
    isIFormat(string)
    -return true if inst is an I-Format inst

*************************************************************************/

bool mips::isIFormat(std::string &op)
{
    std::map<std::string, int>::iterator it = IFormat_map.find(op);
    
    if (it != IFormat_map.end()) return true;
    else return false;
}


/*************************************************************************
    
    input_to_RForm(string, string &)
    -substrings the components of a R-form instruction 

*************************************************************************/

void mips::input_to_RForm(std::string input, std::string &op)
{
    std::string rs, rt, rd;
    
    std::size_t found = input.find("$");
    rd = input.substr(found, 3);
    
    found = input.find("$", found+1);
    rs = input.substr(found, 3);

    found = input.find("$", found+1);
    rt = input.substr(found, 3);
    
    inst = new RForm(input, RFormat_map[op],
                            r.find_in_map(rd),
                            r.find_in_map(rs),
                            r.find_in_map(rt));
}


/*************************************************************************
    
    input_to_IForm(string, string &)
    -substrings the input into components of an I-form instruction

*************************************************************************/

void mips::input_to_IForm(std::string input, std::string &op)
{
    std::string rs, rt, imm;
    std::size_t pos = input.find("$");
    rt = input.substr(pos, 3);

    pos = input.rfind("$");
    rs = input.substr(pos, 3);

    pos = input.rfind(",");
    imm = input.substr(pos+2);
    pos = imm.find_last_not_of("(");
    if (pos != std::string::npos) { imm.erase(pos+1); }

    
    inst = new IForm(input, IFormat_map[op],
                            r.find_in_map(rt),
                            r.find_in_map(rs),
                            std::stoi(imm));
                    
        
    /*
    std::cout << "rt : " << "[" << rt << "]" << std::endl;
    std::cout << "rs : " << "[" << rs << "]" << std::endl;
    std::cout << "imm : " << "[" << imm << "]" << std::endl;
    */

    
    mem[PC()] = inst;
    std::cout << PC() << " " << mem[PC()] << std::endl;

}

/*************************************************************************
    
    input_error()
    -input error detection

*************************************************************************/

void mips::input_error()
{
	std::cout << "Invalid input." << std::endl;
}


/*************************************************************************
    
    cleanup(char, const int)
    -removes unneccesary whitespace from input for uniform instructions
    
    input: "   li     $0,      4"
    output: "li $s0, 4"

*************************************************************************/

std::string cleanup(char *input, const int *MAX_BUF)
{
	std::string retval;
	int i = 0;
	while (i < *MAX_BUF && input[i] != '\0')
	{
		if (input[i] && !(input[i] == ' ' || input[i] == '\t'))
		{
            retval += input[i];
        }
		++i;
	}
    std::size_t pos = retval.find("$");
    retval.insert(pos, " ");
    
    pos = retval.find(",");
    retval.insert(pos+1, " ");
    
    pos = retval.find(",", pos + 1);
    if (pos != std::string::npos) { retval.insert(pos+1, " "); }
    
    std::cout << retval << std::endl;
	return retval;
}







/*************************************************************************

	Assigns each string input with its opcode for I-format instructions

*************************************************************************/

void mips::assign_IFormat()
{
	//opcode_map.insert(std::make_pair("j", 2));
	//opcode_map.insert(std::make_pair("jal", 3));
	//opcode_map.insert(std::make_pair("beq", 4));
	//opcode_map.insert(std::make_pair("bne", 5));
	//opcode_map.insert(std::make_pair("blez", 6));
	//opcode_map.insert(std::make_pair("bgtz", 7));
	IFormat_map.insert(std::make_pair("addi", 8));
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

void mips::assign_RFormat()
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

/*
void mips::assign_pseudo()
{
    //Pseudo_map.insert(std::make_pair("li", 20)
}
*/
