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

    IForm(std::string, int, RegFile &);
    IForm(std::string, int, int, int, int);    
    /* output for individual inst parts */
    int OPCODE()    { return decimal_form[0]; }
    int RS()        { return decimal_form[1]; }
    int RT()        { return decimal_form[2]; }
    int IMMEDIATE() { return decimal_form[3]; }

    virtual int* dec_inst() { return decimal_form; }    
    const static int IMMEDIATE_LENGTH = 16;

private:
    int decimal_form[4];
    
};


#endif 
