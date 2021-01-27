#include <iostream>
#include <bitset>

#include "IForm.h"

IForm::IForm(std::string input, int opcode, RegFile & r)
    : Inst(input, 'I')
{
    std::string reg;
    decimal_form[0] = opcode;
    
    std::size_t found = input.find("$");
    reg = input.substr(found, 3);
    decimal_form[2] = r.find_in_map(reg);
    
    found = input.rfind("$");
    reg = input.substr(found, 3);
    decimal_form[1] = r.find_in_map(reg);
    
    found = input.rfind(",");   
    
    std::string bin_rep;    //string rep of 32 bit instruction, sets the 32bit bitset
    
    /* converts the integers into a binary rep of the inst */
    bin_rep = std::bitset<OPCODE_LENGTH> (OPCODE()).to_string();
    bin_rep += std::bitset<REG_LENGTH> (RS()).to_string();
    bin_rep += std::bitset<REG_LENGTH> (RT()).to_string();
    bin_rep += std::bitset<IMMEDIATE_LENGTH> (IMMEDIATE()).to_string();
    set_machine_code(bin_rep);
}


IForm::IForm(std::string input, int opcode, int rt, int rs, int imm)
    : Inst(input, 'I')
{
    decimal_form[0] = opcode;
    decimal_form[1] = rt;
    decimal_form[2] = rs;
    decimal_form[3] = imm;    

    
    std::string bin_rep;

    bin_rep = std::bitset<OPCODE_LENGTH> (OPCODE()).to_string();
    bin_rep += std::bitset<REG_LENGTH> (RT()).to_string();
    bin_rep += std::bitset<REG_LENGTH> (RS()).to_string();
    bin_rep += std::bitset<IMMEDIATE_LENGTH> (IMMEDIATE()).to_string();

    set_machine_code(bin_rep);


}
