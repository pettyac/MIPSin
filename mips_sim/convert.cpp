#include <iostream>
#include <iomanip>
#include "convert.h"

std::string int_to_hex(unsigned int x)
{
	std::stringstream stream;
	stream << std::hex << x;

	return stream.str();
}


char int_to_char(unsigned int x)
{

	return 0;
}


int hex_to_int(std::string x)
{
	int ret_val = std::stoul(x, nullptr, 16);

	return ret_val;
}


int char_to_int(char)
{
	
	return 0;
}



