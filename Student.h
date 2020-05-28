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
enum Major
{
	ComputerScience, Informatics, InforamtionSystems, AppliedMathematics
};
class Student
{
private:
	char* name;
	unsigned int FacultyNumber;
	unsigned int SemesterCourse;
	Major major;
	unsigned int group;
	Status status;
	double AverageGrade;

	void CopyFrom(const Student& other);
	void Free();
public:

	Student(const char* name, unsigned int FacultyNumber, unsigned int SemesterCourse, Major major, unsigned int group, Status status, double AverageGrade);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	char* GetName();
	unsigned int GetFacultyNumber();
	unsigned int GetSemesterCourse();
	Major GetMajor();
	unsigned int GetGroup();
	Status GetStatus();
	double GetAverageGrade();

	void SetName(char* name);
	void SetCurrentCourse(unsigned int CurrentCourse);
	void SetMajor(Major major);
	void SetGroup(unsigned int group);
	void SetStatus(Status status);
	void SetAverageGrade(double AverageGrade);
	void Print();
};


void Student::CopyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	this->major= other.major;
}
void Student::Free()
{
	delete[] name;
}

Student::Student(const char* name, unsigned int FacultyNumber, unsigned int SemesterCourse, Major major, unsigned int group, Status status, double AverageGrade)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->FacultyNumber = FacultyNumber;
	if (SemesterCourse > 0 && SemesterCourse < 5)
	{
		this->SemesterCourse = SemesterCourse;
	}

	this->major = major;
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

char* Student::GetName()
{
	return name;
}
unsigned int Student::GetFacultyNumber()
{
	return FacultyNumber;
}
unsigned int Student::GetSemesterCourse()
{
	return SemesterCourse;
}
Major Student::GetMajor()
{
	return major;
}
unsigned int Student::GetGroup()
{
	return group;
}
Status Student::GetStatus()
{
	return status;
}
double Student::GetAverageGrade()
{
	return AverageGrade;
}

void Student::SetName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Student::SetCurrentCourse(unsigned int SemesterCourse)
{
	if (SemesterCourse > 0 && SemesterCourse < 5)
	{
		this->SemesterCourse = SemesterCourse;
	}
}
void Student::SetMajor(Major major)
{
	this->major= major;
}
void Student::SetGroup(unsigned int group)
{
	this->group = group;
}
void Student::SetStatus(Status status)
{
	this->status = status;
}
void Student::SetAverageGrade(double AverageGrade)
{
	this->AverageGrade = AverageGrade;
}
void Student::Print()
{
	cout << "name: " << name << endl;
	cout << "faulty number: " << FacultyNumber << endl;
	cout << "semester course: " << SemesterCourse << endl;
	cout << "major: ";
	if (major==Major::AppliedMathematics)
	{
		cout << "Applied Mathematics";
	}
	else if(major==Major::ComputerScience)
	{
		cout << "Computer Science";
	}
	else if (major == Major::Informatics)
	{
		cout << "Informatics";
	}
	else if (major == Major::InforamtionSystems)
	{
		cout << "Inforamtion Systems";
	}
	cout << endl;
	cout << "group: " << group << endl;
	cout << "status: " << status << endl;
	cout << "average grade: " << AverageGrade;

}
