#ifndef BICYCLE_PART_H
#define BICYCLE_PART_H
/*
������ 1. ������������ ����, ���������� ����������� ����. �� �� ������ �� ��� (�������� ���), ���� (������ �����) � ��������

(����� ��� �������� 1, 2 ��� 3).

����� � ������� ����, ��� ����� ��� �� �����, � ������� ���� ����������� ����. (���� ���� �� ���������� ������� �� �����.)

�������� ��������, ����� ������ ��������� ���� � ������� � ������� ���� ���� ����� �����, ����� �� ���������������.
*/

#include <iostream>
#include <fstream>
#include <string>


class BicyclePart
{
public:
	BicyclePart();
	BicyclePart(char*, double, short);
	BicyclePart(const BicyclePart&);
	~BicyclePart();
	BicyclePart&operator=(const BicyclePart&);
	void setName(const char*);
	void setPrice(const double);
	void setQuality(const short);
	short getQuiality()const { return quality; }
	void Serialize(std::ofstream&f)const;
private:
	void CopyName(char*&, const char*);
	void CopyFrom(const BicyclePart&);
private:
	char*name;
	double price;
	short quality;
};




#endif