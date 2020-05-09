#pragma once
#include <iostream>
enum  class Status { enrolled, dropout, graduated };
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

	void CopyFrom(const Student& other);
	void Free();

public:

	Student(const char* name, unsigned int CurrentCourse, const  char* major, unsigned int group, Status status, double AverageGrade);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();
};
//////<BigFour>
void Student::CopyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	strcpy(major, other.major);
}
void Student::Free()
{
	delete[] name;
}
Student::Student(const char* name, unsigned int CurrentCourse, const  char* major, unsigned int group, Status status, double AverageGrade)
{
	this->name = new char[strlen(name) + 1];
	this->CurrentCourse = CurrentCourse;
	strcpy(this->major, major);
	this->group = group;
	this->status = status;
	this->AverageGrade = AverageGrade;
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
