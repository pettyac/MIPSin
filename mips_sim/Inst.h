/********************************************************************

File: Inst.h
Author: Adam Petty

Data structure and parent-class of R and I format MIPS instructions:

format      - set as either 'R', 'I', or 'J' from the appropriate subclass
pseudo_code - MIPS instruction as written with excess whitespace removed,
              i.e., "add $s0, $s0, $s1"
machine_code- 32 bit representation of the instruction


********************************************************************/


#ifndef INST_H
#define INST_H

#include <bitset>
#include <vector>

class Inst
{
public:
    const static int OPCODE_LENGTH = 6;
    const static int REG_LENGTH = 5;
    const static int SHAMT_LENGTH = 5;
    const static int FUNCT_LENGTH = 6;
    const static int IMMEDIATE_LENGTH = 16; 

    Inst(std::string, char);
    
    /* output for instruction members */
    char FORMAT()               { return format; }
    std::bitset<32> MACHINE()   { return machine_code; } 
    std::string INPUT()         { return input; }
    std::vector<int> DEC()      { return decimal_inst; }    
    int OPCODE()    { return decimal_inst[0]; }
    int RS()        { return decimal_inst[1]; }
    int RT()        { return decimal_inst[2]; }
    int RD()        { return decimal_inst[3]; }
    int IMMEDIATE() { return decimal_inst[3]; }
    int SHAMT()     { return decimal_inst[4]; }
    int FUNCT()     { return decimal_inst[5]; }

protected:
    char format;            
    std::string input;
    std::vector<int> decimal_inst;
    std::bitset<32> machine_code;
};

std::ostream & operator<<(std::ostream &, Inst &);
std::ostream & operator<<(std::ostream &, const std::vector<int> &);

#endif
