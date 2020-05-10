#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include "AcademicDisciplines.h"
using namespace std;
enum Status
{
	enrolled, dropout, graduated
};
class Student
{
private:
	char* name;
	unsigned int FacultyNumber;
	unsigned int CurrentCourse;
	char major[50];
	unsigned int group;
	Status status;
	double AverageGrade;
	unsigned int NumberOfDisciplines;
	AcademicDiscipline* Disciplines;

	void CopyFrom(const Student& other);
	void Free();
public:

	Student(const char* name, unsigned int FacultyNumber, unsigned int CurrentCourse, const  char* major, unsigned int group, Status status, double AverageGrade, unsigned int NumberOfDisciplines, AcademicDiscipline* Disciplines);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	//void Print(ostream& strm);
};
//////<BigFour>
void Student::CopyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	strcpy(major, other.major);
	this->Disciplines = new AcademicDiscipline[other.NumberOfDisciplines];
	for (int i = 0; i < other.NumberOfDisciplines; i++)
	{
		this->Disciplines[i] = other.Disciplines[i];
	}
}
void Student::Free()
{
	delete[] name;
}
Student::Student(const char* name, unsigned int FacultyNumber, unsigned int CurrentCourse, const  char* major, unsigned int group, Status status, double AverageGrade, unsigned int NumberOfDisciplines, AcademicDiscipline* Disciplines)
{
	this->name = new char[strlen(name) + 1];
	this->FacultyNumber = FacultyNumber;
	this->CurrentCourse = CurrentCourse;
	strcpy(this->major, major);
	this->group = group;
	this->status = status;
	this->AverageGrade = AverageGrade;
	this->NumberOfDisciplines = NumberOfDisciplines;
	this->Disciplines = new AcademicDiscipline[NumberOfDisciplines];
}
Student::Student(const Student& other)
{
	CopyFrom(other);
}
Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Student::~Student()
{
	Free();
}
//////</BigFour>
