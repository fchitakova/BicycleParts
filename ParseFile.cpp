#include "ParseFile.h"

ParseFile::ParseFile(const char*filename1,const char*filename2)
{
	std::ifstream readfile(filename1, std::ios::in);
	//readfile.open(filename1);
	if(!readfile)
	{
	   throw "Error with the read file";
	}
	std::ofstream writefile(filename2,std::ios::binary | std::ios::out);
	//writefile.open(filename2);
}

ParseFile::~ParseFile()
{
	readfile.close();
	writefile.close();
}

unsigned ParseFile::CountBicyclePartsFirstQuality()
{
	
		int partscnt = 0;

		int i = 0;

		char c;

		char* buffer = new char[MAX_LINELEN];

		while (readfile)
		{
			while (readfile.get(c) && c != '\n')
			{
				buffer[i] = c;
				++i;
			}
			buffer[i] = '\0';
			if (buffer[strlen(buffer) - 1] == '1')
				++partscnt;
			i = 0;
		}
		readfile.clear();
		delete[]buffer;
		return partscnt;
}


void ParseFile::ReadBicyclePartsIntoArray(BicyclePart*parts, size_t cnt)
{
	
		char*buffer = new char[MAX_LINELEN];

		char name[MAX_LINELEN];

		double pr;

		int i = 0;

		int j;

		int arrInx = 0;

		char c;


		readfile.seekg(0, std::ios::beg);
		while (readfile)
		{
			i = 0;
			while (readfile.get(c) && c != '\n')
			{
				buffer[i] = c;
				++i;
			}
			buffer[i] = '\0';
			if (buffer[strlen(buffer) - 1] == '1')
			{
				for (j = 0; isLetter(buffer[j]) || (buffer[j] == ' ' && isLetter(buffer[j + 1])); ++j)
				{
					name[j] = buffer[j];
				}
				name[j] = '\0';

				readfile.seekg(-(int)(strlen(buffer) - strlen(name)) - 1, std::ios::cur);

				readfile>> pr;

				parts[arrInx].setName(name);
				parts[arrInx].setPrice(pr);
				parts[arrInx].setQuality(1);
				++arrInx;
			}
		}
		readfile.clear();
		delete[]buffer;

}


void ParseFile::SerializeFirstQuality(BicyclePart*parts, size_t cnt)
{
	if (!writefile)
	{
		throw "Error with the write file";
	}
	for (size_t i = 0; i < cnt; ++i)
	{
		parts[i].Serialize(writefile);
	}
}

bool isLetter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	return false;
}
