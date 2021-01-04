#ifndef INST_H
#define INST_H

#include <bitset>

class Inst
{
public:
    
    Inst(std::string, std::string, char);
    virtual ~Inst() {}
    
    virtual void dec_form() {}

    void set_machine_code(std::string);
    
    /* output for instruction members */
    char FORMAT()       { return format; }
    std::string PSEUDO()        { return pseudo_code; }
    std::bitset<32> MACHINE()   { return mach_code; } 
    std::string INPUT() { return user_input; }

    
    const static int REG_LENGTH = 5;
    const static int OPCODE_LENGTH = 6;
private:
    char format;            // Set as either 'R', 'I', or 'J'
    std::string pseudo_code;    // cleaned up MIPS instruction 
    std::bitset<32> mach_code;  // 32 bit representation of the instruction
    std::string user_input;     // the users input as typed
};

std::ostream & operator<<(std::ostream &, Inst &);


#endif
