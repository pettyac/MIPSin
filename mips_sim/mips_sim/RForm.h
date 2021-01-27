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
    RForm(std::string, int, RegFile &);
    RForm(std::string, int, int, int, int);
    
    /* output for individual inst parts */
    int OPCODE()    { return decimal_form[0]; }
    int RS()        { return decimal_form[1]; }
    int RT()        { return decimal_form[2]; }
    int RD()        { return decimal_form[3]; }
    int SHAMT()     { return decimal_form[4]; }
    int FUNCT()     { return decimal_form[5]; }

    virtual int* dec_inst() { return decimal_form; }
    
    const static int SHAMT_LENGTH = 5;
    const static int FUNCT_LENGTH = 6;
private:
    int decimal_form[6];
    
};


#endif 
