#pragma once
#pragma warning(disable : 4996)
#pragma warning(disable : 26812)
#include "Student.h"
#include "Vector.h"
enum Type
{
	mandatory, optional
};
class Course
{
private:
	unsigned int ID;
	char* name;
	Type type;
	void CopyFrom(const Course& other);
	void Free();
public:
	Course(unsigned int ID=0, const char* name = "NoName", Type type = mandatory);
	Course(const Course& other);
	Course& operator=(const Course& other);
	~Course();

	char* GetName();
	Type GetType();
	void SetName(char* name);
	void SetType(Type type);
};
void Course::CopyFrom(const Course& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
void Course::Free()
{
	delete[] name;
}
Course::Course(unsigned int ID, const char* name, Type type)
{
	this->ID = ID;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->type = type;
}
Course::Course(const Course& other)
{
	CopyFrom(other);
}
Course& Course::operator=(const Course& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Course::~Course()
{
	Free();
}
char* Course::GetName()
{
	return name;
}
Type Course::GetType()
{
	return type;
}
void Course::SetName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Course::SetType(Type type)
{
	this->type = type;
}

class Grade
{
private:
	Course* course;
	double grade;
public:
	Grade(Course* course=0, double grade=0);
	Course GetCourse();
	double GetGrade();
	void SetGrade(double grade);
};
Grade::Grade(Course* course, double grade)
{
	this->course = course;
	this->grade = grade;
}
Course Grade::GetCourse()
{
	return *course;
}
double Grade::GetGrade()
{
	return grade;
}
void Grade::SetGrade(double grade)
{
	this->grade = grade;
}

class MajorCourseList
{
private:
	Major major;
	unsigned int SemesterCourse;
	Vector<Course*> courses;
public:
	MajorCourseList(Major major, unsigned int SemseterCourse, Vector<Course*> courses)
	{
		this->major = major;
		this->SemesterCourse = SemesterCourse;
		this->courses = courses;
	}
	Course GetCourseByName(char* name);
	unsigned int GetSemesterCourse();
	Major GetMajor()
	{
		return major;
	}
	void AddCourse(Course* course);
};
Course MajorCourseList::GetCourseByName(char* name)
{
	for (int i = 0; i < courses.Size(); i++)
	{
		if (strcmp((courses)[i]->GetName(),name)==0)
		{
			return *courses[i];
		}
		else
		{
			cout << "There is no course with that name!";
		}
	}
}
unsigned int MajorCourseList::GetSemesterCourse()
{
	return SemesterCourse;
}
void MajorCourseList::AddCourse(Course* course)
{
	courses.PushBack(course);
}
