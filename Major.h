#pragma once
#include "Vector.h"
#include "Discipline.h"
using namespace std;
class Major
{
	MajorName name;
	unsigned int years[4];
	Vector<Discipline*> disciplines[4];
public:
	Major();
	Major(MajorName name, Vector<Discipline*> year1, Vector<Discipline*> year2, Vector<Discipline*> year3, Vector<Discipline*> year4);
	MajorName GetMajorName();
	bool SearchDisciplineByYearAndName(unsigned int year, char* name);
	Discipline* GetDisciplineByYearAndName(unsigned int year, char* name);
	Vector<Discipline*> GetDisciplinesVector(unsigned int year);
	void Write(ofstream& file);
};

