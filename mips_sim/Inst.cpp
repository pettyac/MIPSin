#include <iostream>

#include "Inst.h"


Inst::Inst(std::string in, char f) 
        : input(in), format(f)
    {}



std::ostream & operator<<(std::ostream & cout, Inst & inst)
{
    cout << "Instruction Format: " << inst.FORMAT() << std::endl;
    cout << "Input: "              << inst.INPUT() << std::endl;
    cout << "Instruction(MC): "    << inst.MACHINE() << std::endl;
    cout << "Instruction(Dec): "   << inst.DEC() << std::endl;
    return cout; 
}


std::ostream & operator<<(std::ostream & cout, const std::vector<int> & d)
{
    cout << "[";
    for (int i = 0; i < d.size(); ++i)
    {
        cout << d[i];
        cout << (i == d.size() - 1 ? "" : ", ");
    }
    cout << "]";
    
    return cout;
}
