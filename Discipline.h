#pragma once
#include <fstream>
#include "Enums.h"
using namespace std;
class Discipline
{
private:
	char* name;
	Type type;
	void CopyFrom(const Discipline& other);
	void Free();
public:
	Discipline(const char* name = "NoName", Type type=Type::optional);
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

