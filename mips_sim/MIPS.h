#ifndef MIPS_H
#define MIPS_H

#include <iostream>
#include <map>

#include "Inst.h"
#include "RForm.h"
#include "RegFile.h"


class mips
{
public:
	
	mips();
    
    RegFile r;
    Inst *inst;
    	
    	
	int reg[32];		//registers

	std::string find_inst(std::string &);
	void input_error();
	void parse_input(char [], const int*);

    //void translate_inst(IForm &);

	// opcode, and function maps
	
    std::map<std::string, int> RFormat_map;
    std::map<std::string, int> Iform_map;
    
	void map_Iform();			//Populates opcode map
	void map_Rform();			//Populates func map

    
    
private:
   // RegFile r;
};

std::string cleanup(char [], const int*);





#endif
