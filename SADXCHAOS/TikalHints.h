#pragma once
#include "SADXStructs.h"
//"The frog you are looking for Test 123456 is up ahead Testing How 123456789abcde", //max char for entire text box without new line can be 79 characters 
//	"The frog you are looking for Test 123456\nis up ahead Testing How123456789abcdefg", //max char for each line with new line can be up to 81 characters (counting the new line)
//A hint with \n can be 81 character (\n counts as 2)
//A hint with no new line can be 79 charaters
extern const HintText_Text const Hints[67][3];
extern size_t HintSize;
extern int Voices[];
void RandomTikalHint();