#pragma once
#pragma warning(disable : 4996)
#include "Student.h"
enum Type
{
	mandatory, optional
};
class AcademicDiscipline
{
private:
	char* name;
	Type type;
	void CopyFrom(const AcademicDiscipline& other);
	void Free();
public:
	AcademicDiscipline(char* name, Type type);
	AcademicDiscipline(const AcademicDiscipline& other);
	AcademicDiscipline& operator=(const AcademicDiscipline& other);
	~AcademicDiscipline();
};
void AcademicDiscipline::CopyFrom(const AcademicDiscipline& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
void AcademicDiscipline::Free()
{
	delete[] name;
}
AcademicDiscipline::AcademicDiscipline(char* name, Type type)
{
	this->name = new char[strlen(name) + 1];
	this->type = type;
}
AcademicDiscipline::AcademicDiscipline(const AcademicDiscipline& other)
{
	CopyFrom(other);
}
AcademicDiscipline& AcademicDiscipline::operator=(const AcademicDiscipline& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
AcademicDiscipline::~AcademicDiscipline()
{
	Free();
}
