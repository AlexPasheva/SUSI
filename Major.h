#pragma once
#include "Vector.h"
#include "Discipline.h"
#include "Enums.h"
class Major
{
	MajorName name;
	unsigned int years[4];
	Vector<Discipline*> disciplines[4];
public:
	Major();
	Major(MajorName name, Vector<Discipline*> year1, Vector<Discipline*> year2, Vector<Discipline*> year3, Vector<Discipline*> year4);
	bool SearchDisciplineByYearAndName(unsigned int year, char* name);
	Vector<Discipline*> GetDisciplinesVector(unsigned int year);
};

Major::Major()
{
	name = ComputerScience;
	years[0] = 0;
	years[1] = 0;
	years[2] = 0;
	years[3] = 0;
	disciplines[0] = Vector<Discipline*>();
	disciplines[1] = Vector<Discipline*>();
	disciplines[2] = Vector<Discipline*>();
	disciplines[3] = Vector<Discipline*>();
}

Major::Major(MajorName name, Vector<Discipline*> year1, Vector<Discipline*> year2, Vector<Discipline*> year3, Vector<Discipline*> year4)
{
	this->name = name;
	for (int i = 1; i < 5; i++)
	{
		years[i - 1] = i;
	}
	disciplines[0] = year1;
	disciplines[1] = year2;
	disciplines[2] = year3;
	disciplines[3] = year4;
}
bool Major::SearchDisciplineByYearAndName(unsigned int year, char* name)
{
	if (year > 4)
	{
		throw "Invalid year!";
	}
	for (int i = 0; i < disciplines[year - 1].Size(); i++)
	{
		if (strcmp(disciplines[year - 1][i]->GetName(), name) == 0)
		{
			return true;
		}
	}
	return false;
}
Vector<Discipline*> Major::GetDisciplinesVector(unsigned int year)
{
	//trqbva da se dobavq samo ako e mendatory
	return disciplines[year - 1];
}

