#include "Major.h"

Major::Major()
{
	name = MajorName::ComputerScience;
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
MajorName Major::GetMajorName()
{
	return name;
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
Discipline* Major::GetDisciplineByYearAndName(unsigned int year, char* name)
{
	if (year > 4)
	{
		throw "Invalid year!";
	}
	for (int i = 0; i < disciplines[year - 1].Size(); i++)
	{
		if (strcmp(disciplines[year - 1][i]->GetName(), name) == 0)
		{
			return disciplines[year - 1][i];
		}
	}
	throw "There is no discipline with that name in that year!";
}
Vector<Discipline*> Major::GetDisciplinesVector(unsigned int year)
{
	return disciplines[year - 1];
}
void Major::Write(ofstream& file)
{
	file.write((const char*)&name, sizeof(MajorName));
	file.write((const char*)years, 4 * sizeof(unsigned int));

	for (int i = 0; i < 4; i++)
	{
		int len = disciplines[i].Size();
		file.write((const char*)&len, sizeof(int));
		for (int j = 0; j < len; j++)
		{
			file.write((const char*)&disciplines[i][j], sizeof(Discipline*));
		}
	}
}

