#ifndef REGFILE_H
#define REGFILE_H

#include <iostream>
#include <map>

class RegFile
{

public:

    RegFile();

    std::map<std::string, int> register_map;
    void map_registers();
    int find_in_map(std::string);
    
    const static int REGISTERS = 32;    // Number of registers
    const static int REG_LENGTH = 5;    // Bit length of register portion of MIPS Inst
    int reg[REGISTERS];
};

std::ostream & operator<<(std::ostream &, RegFile &);


#endif
