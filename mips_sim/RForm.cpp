#include <iostream>
#include <bitset>

#include "RForm.h"

RForm::RForm(std::string in, std::string pseudo, int func, RegFile & r)
    : Inst(in, pseudo, 'R')
{
    int reg_number[3];      //temp variable for register number
    int i = 0;              //iterates over pseudo inst
    std::string reg_name;   //temp variable for register name
    std::string bin_rep;    //string rep of 32 bit instruction, sets the 32bit bitset

    for (int j = 0; j < 3; ++j)         // find 3 register names in pseudo code
    {
        while (pseudo[i] != '$') ++i;   //skip over whitespace and commas
        
        reg_name = "";
        for (int k = 0; k < 3; ++k)
        {
            reg_name += pseudo[i];
            ++i;
        }
        reg_number[j] = r.find_in_map(reg_name);    //look up register name & find assoc. integer
    }
    

    /* puts integer values of inst in correct order */
    decimal_form[0] = 0;    
    decimal_form[1] = reg_number[1];
    decimal_form[2] = reg_number[2];
    decimal_form[3] = reg_number[0];
    decimal_form[4] = 0;
    decimal_form[5] = func;

    /* converts the integers into a binary rep of the inst */
    bin_rep = std::bitset<OPCODE_LENGTH> (OPCODE()).to_string();
    bin_rep += std::bitset<REG_LENGTH> (RS()).to_string();
    bin_rep += std::bitset<REG_LENGTH> (RT()).to_string();
    bin_rep += std::bitset<REG_LENGTH> (RD()).to_string();
    bin_rep += std::bitset<SHAMT_LENGTH> (SHAMT()).to_string();
    bin_rep += std::bitset<FUNCT_LENGTH> (FUNCT()).to_string();
    set_machine_code(bin_rep);
}


void RForm::dec_form()
{
    std::cout << "< ";
    
    for (int i = 0; i < 6; ++i)
    {
        std::cout << decimal_form[i] << " ";
    }
    std::cout << ">";
}
