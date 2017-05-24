#include "BicyclePart.h"
#include "ParseFile.h"


int main(int argc,const char*argv[])
{
	if (argc < 2)
	{
		std::cerr << "Missing argv.\n";
		return 1;
	}
	
	ParseFile f(argv[1],"report.bin");

	int number = f.CountBicyclePartsFirstQuality();

	if (number==0)
	{
		std::cerr << "There are no first quality parts to be saved!\n";

		return 1;
	}
	BicyclePart*parts = new BicyclePart[number];

	f.ReadBicyclePartsIntoArray(parts, number);

	f.SerializeFirstQuality(parts, number);

	delete[]parts;
	parts = 0;
	return 0;
}