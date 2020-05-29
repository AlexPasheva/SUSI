#pragma once
#include "Enums.h"
class Discipline
{
private:
	char* name;
	Type type;
	MajorName majorName;
	unsigned int year;
	void CopyFrom(const Discipline& other);
	void Free();
public:
	Discipline(const char* name = "NoName", Type type = Type::mandatory, MajorName major = ComputerScience, unsigned int year = 0);
	Discipline(const Discipline& other);
	Discipline& operator=(const Discipline& other);
	~Discipline();

	char* GetName();
	Type GetType();
	MajorName GetMajorName();
	unsigned int GetYear();
	void SetYear(unsigned int year);
	void SetMajorName(MajorName majorName);
	void SetName(char* name);
	void SetType(Type type);

};
void Discipline::CopyFrom(const Discipline& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
void Discipline::Free()
{
	delete[] name;
}
Discipline::Discipline(const char* name, Type type, MajorName majorName = ComputerScience, unsigned int year = 0)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->type = type;
	this->majorName = majorName;
	this->year = year;
}
Discipline::Discipline(const Discipline& other)
{
	CopyFrom(other);
}
Discipline& Discipline::operator=(const Discipline& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Discipline::~Discipline()
{
	Free();
}
char* Discipline::GetName()
{
	return name;
}
Type Discipline::GetType()
{
	return type;
}
MajorName Discipline::GetMajorName()
{
	return majorName;
}
unsigned int Discipline::GetYear()
{
	return year;
}
void Discipline::SetYear(unsigned int year)
{
	this->year = year;
}
void Discipline::SetMajorName(MajorName majorName)
{
	this->majorName = majorName;
}
void Discipline::SetName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Discipline::SetType(Type type)
{
	this->type = type;
}
