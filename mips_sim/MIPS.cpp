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
    : pc(0)
{
    assign_RFormat();
    assign_IFormat();
}


/*************************************************************************
    
    parse_input(char, const int)
    -reads the instruction from the input

*************************************************************************/

std::string mips::parse_input(std::string in)
{
    //std::string input = cleanup(in);   // remove whitespace
    std::string opcode = get_opcode(in);
    try
    {
        if (is_IFormat(opcode) || is_RFormat(opcode))
        {
            //std::cout << "Is valid" << std::endl;
            return in;
        }
        else 
        {
            throw "Invalid instruction";
        }
    }
    catch(char const* s)
    {
        return s;
    }
}

/*************************************************************************
    
    cleanup(char*)
    -removes unneccesary whitespace from input for uniform instructions
    
    input: "   li     $0,      4"
    output: "li $s0, 4"

*************************************************************************/

std::string cleanup(char* raw_input)
{
    //std::cout << "In cleanup" << std::endl;
	std::string input;
	int i = 0;
	while (raw_input[i] != '\0')
	{
		if (raw_input[i] && !(raw_input[i] == ' ' ||raw_input[i] == '\t'))
		{
            input += raw_input[i];
        }
		++i;
	}

    std::size_t pos = input.find("$");
    input.insert(pos, " ");
    
    pos = input.find(",");
    input.insert(pos+1, " ");
    
    pos = input.find(",", pos + 1);
    if (pos != std::string::npos) { input.insert(pos+1, " "); }
    
	return input;
}


/*************************************************************************
    
    find_inst(string)
    -

*************************************************************************/

std::string mips::get_opcode(std::string &input)
{
    //std::cout << "In get_opcode" << std::endl;
    std::size_t pos = input.find(" ");
    std::string opcode = input.substr(0, pos);
    return opcode;
}


/*************************************************************************
    
    isRFormat(string)
    -return true if inst is a R-Format inst

*************************************************************************/

bool mips::is_RFormat(std::string &opcode)
{
    std::map<std::string, int>::iterator it = RFormat_map.find(opcode);
    return (it != RFormat_map.end()) ? true : false;
}


/*************************************************************************
    
    isIFormat(string)
    -return true if inst is an I-Format inst

*************************************************************************/

bool mips::is_IFormat(std::string &opcode)
{
    std::map<std::string, int>::iterator it = IFormat_map.find(opcode);
    return (it != IFormat_map.end()) ? true : false;
}

Inst* mips::create_inst(std::string &input)
{
    //std::cout << "create_inst" << std::endl;
    std::string opcode = get_opcode(input);

    if (is_IFormat(opcode))
    {
        return input_to_IForm(input, opcode);
    }
    else if (is_RFormat(opcode))
    {
        return input_to_RForm(input, opcode);
    } 
}

/*************************************************************************
    
    input_to_RForm(string, string &)
    -substrings the components of a R-form instruction 

*************************************************************************/

Inst* mips::input_to_RForm(std::string input, std::string opcode)
{
    
    std::cout << "input_to_Rform" << std::endl;
    std::string rs, rt, rd;

    std::size_t pos = input.find("$");
    rd = input.substr(pos, 3);
    
    pos = input.find("$", pos+1);
    rs = input.substr(pos, 3);

    pos = input.find("$", pos+1);
    rt = input.substr(pos, 3);
    
    return new RForm(input, RFormat_map[opcode],
                            r.find_in_map(rd),
                            r.find_in_map(rs),
                            r.find_in_map(rt));
}

/*************************************************************************
    
    input_to_IForm(string, string &)
    -substrings the input into components of an I-form instruction

*************************************************************************/

Inst* mips::input_to_IForm(std::string input, std::string opcode)
{
    std::cout << "input_to_Iform" << std::endl;

    std::string rs, rt, imm;
    std::size_t pos = input.find("$");
    rt = input.substr(pos, 3);

    pos = input.rfind("$");
    rs = input.substr(pos, 3);

    pos = input.rfind(",");
    imm = input.substr(pos+2);
    pos = imm.find_last_not_of("(");
    if (pos != std::string::npos) { imm.erase(pos+1); }
    
    return new IForm(input, IFormat_map[opcode],
                            r.find_in_map(rt),
                            r.find_in_map(rs),
                            std::stoi(imm));
  
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
	IFormat_map.insert(std::make_pair("addiu", 9));
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
	RFormat_map.insert(std::make_pair("mult", 24));
	RFormat_map.insert(std::make_pair("multu", 25));
	//func_map.insert(std::make_pair("div", 26));
	//func_map.insert(std::make_pair("divu", 27));
	RFormat_map.insert(std::make_pair("add", 32));
	RFormat_map.insert(std::make_pair("addu", 33));
	RFormat_map.insert(std::make_pair("sub", 34));
	RFormat_map.insert(std::make_pair("subu", 35));
	//func_map.insert(std::make_pair("and", 36));
	//func_map.insert(std::make_pair("or", 37));
	//func_map.insert(std::make_pair("xor", 38));
	//func_map.insert(std::make_pair("nor", 39));
	//R_format_map.insert(std::make_pair("move", 40));
}

void mips::add_inst_to_mem(Inst *inst)
{
    std::cout << "added to memory" << std::endl;
    mem[PC()] = inst;
}

void mips::execute_inst()
{
    std::cout << "executing from memory" << std::endl;
    Inst* inst = fetch_inst(PC());
    pc++;

    if (inst->FORMAT() == 'R')
    {
        switch(inst->FUNCT())
        {
            case 24:
                mult(inst);
                break;
            case 25:
                multu(inst);
                break;
            case 32:
                add(inst);
                break;
            case 33:
                addu(inst);
                break;
            case 34:
                sub(inst);
                break;
        }

    }

    else if (inst->FORMAT() == 'I')
    {
        switch(inst->OPCODE())
        {
            case 8:
                addi(inst);
                break;
            case 9:
                addiu(inst);
                break;
        }
    }
}

Inst* mips::fetch_inst(unsigned int _pc)
{
    return mem[_pc];
}

void mips::add(Inst* inst)
{
    r.reg[inst->RD()] = r.reg[inst->RS()] + r.reg[inst->RT()];
}

void mips::addu(Inst* inst)
{
    r.reg[inst->RD()] = r.reg[inst->RS()] + r.reg[inst->RT()];
}

void mips::addi(Inst* inst)
{
    r.reg[inst->RT()] = r.reg[inst->RS()] + inst->IMMEDIATE();
}

void mips::addiu(Inst* inst)
{  
    r.reg[inst->RT()] = r.reg[inst->RS()] + inst->IMMEDIATE();
}

void mips::sub(Inst* inst)
{
    r.reg[inst->RD()] = r.reg[inst->RS()] - r.reg[inst->RT()];
}

void mips::subu(Inst* inst)
{
    r.reg[inst->RD()] = r.reg[inst->RS()] - r.reg[inst->RT()];
}

void mips::mult(Inst* inst)
{
    r.reg[inst->RD()] = r.reg[inst->RS()] * r.reg[inst->RT()];
}

void mips::multu(Inst* inst)
{
    r.reg[inst->RD()] = r.reg[inst->RS()] * r.reg[inst->RT()];
}