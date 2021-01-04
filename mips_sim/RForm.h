#ifndef RFORM_H
#define RFORM_H

#include <map>

#include "Inst.h"
#include "RegFile.h"

class RForm : public Inst
{
public:

    RForm(std::string, std::string, int, RegFile &);
    
    /* output for individual inst parts */
    int OPCODE()    { return decimal_form[0]; }
    int RS()        { return decimal_form[1]; }
    int RT()        { return decimal_form[2]; }
    int RD()        { return decimal_form[3]; }
    int SHAMT()     { return decimal_form[4]; }
    int FUNCT()     { return decimal_form[5]; }
    virtual void dec_form();
    
    const static int SHAMT_LENGTH = 5;
    const static int FUNCT_LENGTH = 6;
private:
    int decimal_form[6];
    
};


#endif 
