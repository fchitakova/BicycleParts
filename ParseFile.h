#ifndef PARSEFILE_H
#define PARSEFILE_H

#include "BicyclePart.h"

const int MAX_LINELEN = 500;

class ParseFile
{
public:
ParseFile(const char*filename1,const char*filename2); //first for txt file ,second for bin
~ParseFile();
unsigned CountBicyclePartsFirstQuality();
void ReadBicyclePartsIntoArray(BicyclePart*parts, size_t cnt);
void SerializeFirstQuality(BicyclePart*parts, size_t cnt);
private:
	std::ifstream readfile;
	std::ofstream writefile;
};

bool isLetter(char);

#endif