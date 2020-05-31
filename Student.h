#pragma once
#pragma warning(disable : 4996)
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

	Student(const char* name = "NoName", unsigned int FacultyNumber = 1000, unsigned int year = 0, Major* major = new Major(), MajorName majorMame = MajorName::ComputerScience, unsigned int group = 0, Status status = Status::enrolled, Vector<Discipline*> disciplines=Vector<Discipline*>(), Vector<double> grades=Vector<double>());
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	char* GetName();
	unsigned int GetFacultyNumber();
	unsigned int GetYear();
	MajorName GetMajorName();
	unsigned int GetGroup();
	Status GetStatus();
	double GetAverageGrade();
	Student& GetStudentByFN(unsigned int fn);

	void SetName(char* name);
	void SetYear(unsigned int year);
	void SetMajorName(MajorName majorName);
	void SetGroup(unsigned int group);
	void SetStatus(Status status);

	void Print();
	void Enroll(char* NameOfDiscipline);
	void Advance();
	void Report();
	void Graduate();
	void Interrupt();
	void Resume();
	void AddGrade(char* DisciplineName, double grade);
	void ChangeProgram(Major* major);
	void ChandeGroup(unsigned int group);
	void ChangeYear(unsigned int year);
	void Protocol();

	void WriteStudent(ofstream& f);
};
