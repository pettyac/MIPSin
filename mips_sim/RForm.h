/********************************************************************

File: RForm.h
Author: Adam Petty

Data structure and subclass of Inst for R-Format MIPS instructions:

    -----------------------------------------------
    | OPCODE |  RS  |  RT  |  RD  | SHAMT | FUNCT |
    ----------------------------------------------- 
    |31    26|25  21|20  16|15  11|10    6|5     0|
    -----------------------------------------------

Fields:

OPCODE = operation of the instruction
RS = first register source
RT = second register source
RD = destination register, result of the op
SHAMT = shift amount
FUNCT = function, selects specific variant of the op 

decimal_form[] = array of fields in the above order.
********************************************************************/

#ifndef RFORM_H
#define RFORM_H

#include <map>

#include "Inst.h"
#include "RegFile.h"

class RForm : public Inst
{
public:
    RForm(std::string input, int funct, int rd, int rs, int rt)
        : Inst(input, 'R')
    {
        decimal_inst.push_back(0);
        decimal_inst.push_back(rs);
        decimal_inst.push_back(rt);
        decimal_inst.push_back(rd);
        decimal_inst.push_back(0);
        decimal_inst.push_back(funct);
               
        /* converts the integers into a binary rep of the inst */
        std::string bin_rep;
        bin_rep = std::bitset<OPCODE_LENGTH> (OPCODE()).to_string();
        bin_rep += std::bitset<REG_LENGTH> (RS()).to_string();
        bin_rep += std::bitset<REG_LENGTH> (RT()).to_string();
        bin_rep += std::bitset<REG_LENGTH> (RD()).to_string();
        bin_rep += std::bitset<SHAMT_LENGTH> (SHAMT()).to_string();
        bin_rep += std::bitset<FUNCT_LENGTH> (FUNCT()).to_string();

        set_machine_code(bin_rep);
    }
};

#endif 
