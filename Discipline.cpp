#include "Discipline.h"
#include <iostream>
using namespace std;
void Discipline::CopyFrom(const Discipline& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
void Discipline::Free()
{
	delete[] name;
}
Discipline::Discipline(const char* name, Type type)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->type = type;
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
void Discipline::SetName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Discipline::SetType(Type type)
{
	this->type = type;
}
void Discipline::Print()
{
	cout << "name: " << name << " type: ";
	if (type == Type::mandatory)
	{
		cout << "mandatory ";
	}
	else
	{
		cout << "optional ";
	}
}
bool Discipline::operator==(const Discipline& other)
{
	if (strcmp(this->name, other.name) == 0)
	{
		return true;
	}
	return false;
}
void Discipline::Write(ofstream& file)
{
	int strLen = strlen(name);
	file.write((const char*)&strLen, sizeof(int));
	file.write(name, strLen);
	file.write((const char*)&type, sizeof(Type));
}
