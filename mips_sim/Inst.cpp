#include <iostream>

#include "Inst.h"


Inst::Inst(std::string in, char f) 
        : input(in), format(f)
    {}



std::ostream & operator<<(std::ostream & cout, Inst & inst)
{
    cout << " Instruction Format: " << inst.FORMAT() << std::endl;
    cout << " input: "         << inst.INPUT() << std::endl;
    cout << " Machine code: "       << inst.MACHINE() << std::endl;
    return cout; 
    
}



void Inst::set_machine_code(std::string in)
{
    machine_code = std::bitset<32>(in);
}
