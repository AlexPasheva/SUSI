#pragma once
using namespace std;
#include <fstream>
#include "Enums.h"
class Discipline
{
private:
	char* name;
	Type type;
	void CopyFrom(const Discipline& other);
	void Free();
public:
	Discipline(const char* name = "NoName", Type type=Type::optional);
	Discipline(char* name, Type type);
	Discipline(const Discipline& other);
	Discipline& operator=(const Discipline& other);
	~Discipline();

	char* GetName();
	Type GetType();
	void SetName(char* name);
	void SetType(Type type);

	void Print();
	bool operator==(const Discipline& other);
	void Write(ofstream& file);
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
Discipline::Discipline(const char* name, Type type = Type::optional)
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
	cout << "name: " << name << "type: ";
	if (type==Type::mandatory)
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
	if (strcmp(this->name,other.name)==0)
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
	file.write((const char*)&type, sizeof(Type)); //sizeof(int) is 4
}
Discipline Read(ifstream& file)
{
	int nameLen;
	file.read((char*)&nameLen, sizeof(int));

	char* name = new char[nameLen + 1];
	file.read(name, nameLen);
	name[nameLen] = '\0';

	Type type;
	file.read((char*)&type, sizeof(Type));

	Discipline newDis(name, type);
	return newDis;
	delete[] name;
}
