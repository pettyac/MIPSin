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
	
    std::string parse_input(std::string);
	std::string get_opcode(std::string &);
    void input_error();

    bool is_RFormat(std::string &);
    bool is_IFormat(std::string &);
    
    Inst* input_to_RForm(std::string, std::string);
    Inst* input_to_IForm(std::string, std::string);
    
    Inst* create_inst(std::string &);
    void assign_RFormat();			// populates func maip
	void assign_IFormat();			// populates opcode map

    unsigned int PC() { return pc; } 
    void add_inst_to_mem(Inst *);
    void execute_inst();
    Inst* fetch_inst(unsigned int);
    std::map<std::string, int> RFormat_map;     // map of R-form instructions. i.e., (beq, 4)
    std::map<std::string, int> IFormat_map;     // map of I-form instructions. i.e., (add, 32)
	       
    void add(Inst*);
    void addi(Inst*);
    void addiu(Inst*);
    void addu(Inst*);
    void sub(Inst*);
    void subu(Inst*);
    void mult(Inst*);
    void multu(Inst*);

private:
   // RegFile r;
    std::map<unsigned int, Inst*> mem;
    int reg[32];
    unsigned int pc = 0;
};

std::string cleanup(char []);





#endif
