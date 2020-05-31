#pragma once
#include "Database.h"
Student ReadStudent(ifstream& f)
{
	int nameLen = 0;
	f.read((char*)&nameLen, sizeof(int));
	char* name = new char[nameLen + 1];
	f.read(name, nameLen);
	name[nameLen] = '\0';
	unsigned int fn = 0;
	f.read((char*)&fn, sizeof(unsigned int));
	unsigned int year = 0;
	f.read((char*)&year, sizeof(unsigned int));
	MajorName majorName;
	f.read((char*)&majorName, sizeof(MajorName));
	Major* major;
	f.read((char*)&major, sizeof(Major*));
	unsigned int group = 0;
	f.read((char*)&majorName, sizeof(unsigned int));
	Status status;
	f.read((char*)&status, sizeof(Status));
	double AverageGrade = 0;
	f.read((char*)&AverageGrade, sizeof(double));
	int disLen = 0;
	f.read((char*)&disLen, sizeof(double));
	Vector<Discipline*> disciplines;
	f.read((char*)&disciplines, sizeof(Discipline*) * disLen);
	Vector<double> grades;
	f.read((char*)&grades, sizeof(double) * disLen);

	Student NewSt(name, fn, year, major, majorName, group, status, disciplines, grades);
	delete[] name;
	return NewSt;
}
Major ReadMajor(ifstream& file)
{
	MajorName name;
	unsigned int years[4];
	Vector<Discipline*> year1;
	Vector<Discipline*> year2;
	Vector<Discipline*> year3;
	Vector<Discipline*> year4;
	Discipline* n;
	unsigned int len;
	file.read((char*)&name, sizeof(MajorName));
	file.read((char*)years, 4 * sizeof(unsigned int));
	int nlen = 0;
	file.read((char*)&nlen, sizeof(int));
	for (int j = 0; j < nlen; j++)
	{
		file.read((char*)&n, sizeof(Discipline*));
		year1.PushBack(n);
	}
	file.read((char*)&nlen, sizeof(int));
	for (int j = 0; j < nlen; j++)
	{
		file.read((char*)&n, sizeof(Discipline*));
		year2.PushBack(n);
	}
	file.read((char*)&nlen, sizeof(int));
	for (int j = 0; j < nlen; j++)
	{
		file.read((char*)&n, sizeof(Discipline*));
		year3.PushBack(n);
	}
	file.read((char*)&nlen, sizeof(int));
	for (int j = 0; j < nlen; j++)
	{
		file.read((char*)&n, sizeof(Discipline*));
		year4.PushBack(n);
	}
	Major newMaj(name, year1, year2, year3, year4);
	return newMaj;
}
ListOfAllStudents ReadListOfStudents(ifstream& file)
{
	int Len;
	file.read((char*)&Len, sizeof(int));
	Vector<Student> students;
	for (int i = 0; i < Len; i++)
	{
		students.PushBack(ReadStudent(file));
	}
	ListOfAllStudents NewList(students);
	return NewList;
}
Discipline ReadDiscipline(ifstream& file)
{
	int nameLen;
	file.read((char*)&nameLen, sizeof(int));

	char* name = new char[nameLen + 1];
	file.read(name, nameLen);
	name[nameLen] = '\0';

	Type type;
	file.read((char*)&type, sizeof(Type));

	Discipline newDis(name, type);
	delete[] name;
	return newDis;
}
Database ReadDatabase(ifstream& f)
{
	Vector<Discipline> disciplines[16];
	Vector<Major> majors[4];
	ListOfAllStudents students;
	int len;
	for (int i = 0; i < 16; i++)
	{
		f.read((char*)&len, sizeof(int));;
		for (int j = 0; j < len; j++)
		{
			disciplines[i][j] = ReadDiscipline(f);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		f.read((char*)&len, sizeof(int));;
		for (int j = 0; j < len; j++)
		{
			majors[i][j] = ReadMajor(f);
		}
	}
	students = ReadListOfStudents(f);
	Database data(disciplines, majors, students);
	return data;
}