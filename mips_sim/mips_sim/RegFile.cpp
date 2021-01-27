#include "RegFile.h"
#include "convert.h"

#include <iostream>
#include <iomanip>

std::ostream & operator<<(std::ostream & cout, RegFile & r)
{
    cout << "================================================================"
         << std::endl
		 << "                          DATA SEGMENT"
	     << std::endl
	     << "================================================================"
		 << std::endl
		 << "  addr (hex)   | reg | value (int) | value (hex) | value (char)|"
		 << std::endl
		 << "---------------+-----+-------------+-------------+-------------+"
		 << std::endl;
    
   
    for (std::map<std::string, int>::iterator it = r.register_map.begin(); it != r.register_map.end(); ++it)
    {
        cout << &(r.reg[it->second]) << " |";       // address of the register
        cout << std::setw(4) << it->first << " |";      // the register name
        cout << std::setw(13) << r.reg[it->second] << "|";
        cout << std::setw(13) << int_to_hex(r.reg[it->second]) << "|";


        cout << std::endl; 
    }


    cout << "============================================================="
	     << std::endl
		 << "Labels"
    	 << std::endl
		 << "============================================================="
		 << std::endl;

    return cout;
}


RegFile::RegFile()
{
    for (int i = 0; i < REGISTERS; ++i)
    {
        reg[i] = 0;
    }

    //map items
    map_registers();
}


int RegFile::find_in_map(std::string in)
{
    std::map<std::string, int>::iterator it = register_map.find(in);
    int retval;
    
    if (it != register_map.end())
    {
        retval = it->second;
    }
    else retval = 99;
    
    return retval;
}


/*************************************************************************

	Assigns each string input with its associated register number
    TODO: switch to map[i] style pairing

*************************************************************************/

void RegFile::map_registers()
{
	register_map["$0"] = 0;
    register_map["$at"] = 1;
    register_map["$v0"] = 2;
    register_map["$v1"] = 3;
    register_map["$a0"] = 4;	
	register_map["$a1"] = 5;	
	register_map["$a2"] = 6;	
	register_map["$a3"] = 7;	
	register_map["$t0"] = 8;	
	register_map["$t1"] = 9;	
	register_map["$t2"] = 10;	
	register_map["$t3"] = 11;	
	register_map["$t4"] = 12;	
	register_map["$t5"] = 13;	
	register_map["$t6"] = 14;	
	register_map["$t7"] = 15;	
	register_map["$s0"] = 16;	
	register_map["$s1"] = 17;	
	register_map["$s2"] = 18;	
	register_map["$s3"] = 19;	
	register_map["$s4"] = 20;	
	register_map["$s5"] = 21;	
	register_map["$s6"] = 22;	
	register_map["$s7"] = 23;	
	register_map["$t8"] = 24;	
	register_map["$t9"] = 25;	
	//registers.nsert(std::make_pair("$k0", reg[26]));	
	//registers.insert(std::make_pair("$k1", reg[27]));	
	//registers.insert(std::make_pair("$gp", reg[28]));	
	register_map["$sp"] = 29;	
	register_map["$s8"] = 30;	
	register_map["$ra"] = 31;
	register_map["lo"] = 32;
	register_map["hi"] = 33;
}
