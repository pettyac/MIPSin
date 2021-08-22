/********************************************************************

File: IForm.h
Author: Adam Petty

Data structure and subclass of Inst for I-Format MIPS instructions:

    -----------------------------------------------
    | OPCODE |  RS  |  RT  |      IMMEDIATE       |
    ----------------------------------------------- 
    |31    26|25  21|20  16|15                   0|
    -----------------------------------------------

Fields:

OPCODE = operation of the instruction
RS = first register source
RT = second register source

decimal_form[] = array of fields in the above order.

********************************************************************/

#ifndef IFORM_H
#define IFORM_H

#include <map>

#include "Inst.h"
#include "RegFile.h"

class IForm : public Inst
{
public:
    IForm(std::string input, int opcode, int rt, int rs, int imm)
        : Inst(input, 'I')
    {
        decimal_inst.push_back(opcode);
        decimal_inst.push_back(rt);
        decimal_inst.push_back(rs);
        decimal_inst.push_back(imm);
        decimal_inst.shrink_to_fit();
           
        std::string bin_rep;
        bin_rep = std::bitset<OPCODE_LENGTH> (OPCODE()).to_string();
        bin_rep += std::bitset<REG_LENGTH> (RT()).to_string();
        bin_rep += std::bitset<REG_LENGTH> (RS()).to_string();
        bin_rep += std::bitset<IMMEDIATE_LENGTH> (IMMEDIATE()).to_string();
        machine_code = std::bitset<32>(bin_rep); 
    }
};


#endif 
