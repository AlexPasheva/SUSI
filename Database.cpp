#include "Database.h"
Database::Database()
{
	for (int i = 0; i < 16; i++)
	{
		this->disciplines[i] = Vector<Discipline>();
	}
	for (int i = 0; i < 4; i++)
	{
		this->majors[i] = Vector<Major>();
	}
	this->students = ListOfAllStudents();
}
Database::Database(Vector<Discipline> disciplines[16], Vector<Major> majors[4], ListOfAllStudents students)
{
	for (int i = 0; i < 16; i++)
	{
		this->disciplines[i] = disciplines[i];
	}
	for (int i = 0; i < 4; i++)
	{
		this->majors[i] = majors[i];
	}
	this->students = students;
}
void Database::WriteDatabase(ofstream& f)
{
	for (int i = 0; i < 16; i++)
	{
		int len = disciplines[i].Size();
		f.write((const char*)&len, sizeof(int));
		for (int j = 0; j < len; j++)
		{
			disciplines[i][j].Write(f);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int len = majors[i].Size();
		f.write((const char*)&len, sizeof(int));
		for (int j = 0; j < len; j++)
		{
			majors[i][j].Write(f);
		}
	}
	students.Write(f);
}