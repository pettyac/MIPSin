#include <iostream>

#include "Inst.h"


std::ostream & operator<<(std::ostream & cout, Inst & inst)
{
    cout << " Instruction Format: " << inst.FORMAT() << std::endl;
    cout << " user_input: "         << inst.INPUT() << std::endl;
    cout << " mips inst: "          << inst.PSEUDO() << std::endl;
    cout << " Machine code: "       << inst.MACHINE() << std::endl;
    inst.dec_form();
    return cout; 
    
}


Inst::Inst(std::string in, std::string pseudo, char _format)
        : user_input(in), pseudo_code(pseudo), format(_format)
    {}


void Inst::set_machine_code(std::string in)
{
    mach_code = std::bitset<32>(std::string(in));
}
