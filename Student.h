#pragma once

#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include "Major.h"
using namespace std;

class Student
{
private:
	char* name;
	unsigned int FacultyNumber;
	unsigned int year;
	MajorName majorName;
	Major* major;
	unsigned int group;
	Status status;
	double AverageGrade;
	Vector<Discipline*> disciplines;
	Vector<double> grades;

	void CopyFrom(const Student& other);
	void Free();
public:

	Student(const char* name = "NoName", unsigned int FacultyNumber = 1000, unsigned int year = 0, Major* major = new Major(), MajorName majorMame = ComputerScience, unsigned int group = 0, Status status = Status::enrolled, double AverageGrade = 0);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	char* GetName();
	unsigned int GetFacultyNumber();
	unsigned int GetYear();
	//Major GetMajorName();
	unsigned int GetGroup();
	Status GetStatus();
	double GetAverageGrade();
	Student& GetStudentByFN(unsigned int fn);

	void SetName(char* name);
	void SetYear(unsigned int year);
	void SetMajorName(MajorName majorName);
	void SetGroup(unsigned int group);
	void SetStatus(Status status);
	void SetAverageGrade(double AverageGrade);


	void Print();
};

Student::Student(const char* name, unsigned int FacultyNumber, unsigned int year, Major* major, MajorName majorMame, unsigned int group, Status status, double AverageGrade)
{

}

void Student::CopyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	this->majorName = other.majorName;
}
void Student::Free()
{
	delete[] name;
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
unsigned int Student::GetYear()
{
	return year;
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
Student& Student::GetStudentByFN(unsigned int fn)
{
	if (fn == FacultyNumber)
	{
		return *this;
	}
}

void Student::SetName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Student::SetYear(unsigned int year)
{
	if (year > 0 && year < 5)
	{
		this->year = year;
	}
}
void Student::SetMajorName(MajorName majorName)
{
	this->majorName = majorName;
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
	cout << "semester course: " << year << endl;
	cout << "major: ";
	if (majorName == AppliedMathematics)
	{
		cout << "Applied Mathematics";
	}
	else if (majorName == MajorName::ComputerScience)
	{
		cout << "Computer Science";
	}
	else if (majorName == MajorName::Informatics)
	{
		cout << "Informatics";
	}
	else if (majorName == MajorName::InforamtionSystems)
	{
		cout << "Inforamtion Systems";
	}
	cout << endl;
	cout << "group: " << group << endl;
	cout << "status: ";//<< status << endl;
	cout << "average grade: " << AverageGrade;

}
