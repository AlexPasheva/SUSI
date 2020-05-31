#pragma once
#include "ListOfAllStudents.h"
class Database
{
private:
	Vector<Discipline> disciplines[16];// za vseki 4 majora po 4 godini s disciplini 
	Vector<Major> majors[4];// 4te majora
	ListOfAllStudents students;// vsichki studenti
public:
	Database();
	Database(Vector<Discipline> disciplines[16], Vector<Major> majors[4], ListOfAllStudents students);
	void WriteDatabase(ofstream& f);
};

