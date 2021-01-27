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

class Inst
{
public:
    
    Inst(std::string, char);
    virtual ~Inst() {}
    

    void set_machine_code(std::string);
    
    /* output for instruction members */
    char FORMAT()               { return format; }
    std::bitset<32> MACHINE()   { return machine_code; } 
    std::string INPUT()         { return input; }
    virtual int* dec_inst()      { return NULL; }
        
    const static int REG_LENGTH = 5;
    const static int OPCODE_LENGTH = 6;
private:
    char format;            
    std::string input;     
    std::bitset<32> machine_code;  
};

std::ostream & operator<<(std::ostream &, Inst &);


#endif
