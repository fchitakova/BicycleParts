#ifndef BICYCLE_PART_H
#define BICYCLE_PART_H
/*
Задача 1. Реализирайте клас, представящ велосипедна част. Тя се състои от име (символен низ), цена (реално число) и качество

(число със стойност 1, 2 или 3).

Даден е текстов файл, във всеки ред на който, е описана една велосипедна част. (Може сами да определите формата на файла.)

Напишете програма, която изчита текстовия файл и записва в двоичен файл само онези части, които са първокачествени.
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