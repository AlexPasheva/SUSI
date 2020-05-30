#pragma once
#include "Commands.h"

class Database
{
private:
	Vector<Discipline> disciplines[16];// za vseki 4 majora po 4 godini s disciplini 
	Vector<Major> majors[4];// 4te majora
	ListOfAllStudents students;// vsichki studenti
public:
	Database();
	Database(Vector<Discipline> disciplines[16], Vector<Major> majors[4], ListOfAllStudents students);
	
};
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
	this->students=ListOfAllStudents();
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
