#ifndef MIPS_H
#define MIPS_H

#include <iostream>
#include <map>

#include "RForm.h"
#include "IForm.h"
#include "RegFile.h"


class mips
{
public:
	
	mips();

    
    RegFile r;      // memory and registers of the instance
    
    	
    // functions for interpreting input
	
    void parse_input(char [], const int*);
	std::string find_inst(std::string &);
	int fetch(int);
    void input_error();

    bool isRFormat(std::string &);
    bool isIFormat(std::string &);
    
    void input_to_RForm(std::string, std::string &);
    void input_to_IForm(std::string, std::string &);
    
    void assign_RFormat();			// populates func maip
	void assign_IFormat();			// populates opcode map

    int PC() { return _PC; } 
    
    std::map<std::string, int> RFormat_map;     // map of R-form instructions. i.e., (beq, 4)
    std::map<std::string, int> IFormat_map;     // map of I-form instructions. i.e., (add, 32)
	   
    Inst *inst;
    
private:
   // RegFile r;
    std::map<unsigned long int, Inst*> mem;
    int reg[32];
    int _PC;
};

std::string cleanup(char [], const int*);





#endif
