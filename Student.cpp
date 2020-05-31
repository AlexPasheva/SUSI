#include "Student.h"
#include <iostream>
Student::Student(const char* name, unsigned int FacultyNumber, unsigned int year, Major* major, MajorName majorName, unsigned int group, Status status, Vector<Discipline*> disciplines, Vector<double> grades)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->FacultyNumber = FacultyNumber;
	this->year = year;
	this->major = major;
	this->majorName = majorName;
	this->group = group;
	this->status = status;
	this->disciplines = disciplines;
	this->grades = grades;
	AverageGrade = 0;
	for (int i = 0; i < grades.Size(); i++)
	{
		AverageGrade += grades[i];
	}
	AverageGrade /= grades.Size();
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
MajorName Student::GetMajorName()
{
	return majorName;
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
	AverageGrade = 0;
	for (int i = 0; i < grades.Size(); i++)
	{
		AverageGrade += grades[i];
	}
	AverageGrade /= grades.Size();
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

void Student::Print()
{
	cout << "name: " << name << endl;
	cout << "faulty number: " << FacultyNumber << endl;
	cout << "semester course: " << year << endl;
	cout << "major: ";
	if (majorName == MajorName::AppliedMathematics)
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
	for (int i = 0; i < disciplines.Size(); i++)
	{
		disciplines[i]->Print();
		cout << "grade: " << grades[i];
	}
	AverageGrade = 0;
	for (int i = 0; i < grades.Size(); i++)
	{
		AverageGrade += grades[i];
	}
	AverageGrade /= grades.Size();
	cout << "average grade: " << AverageGrade << endl;
}
void Student::Enroll(char* NameOfDiscipline)
{
	if (this->status == Status::dropout || this->status == Status::graduated)
	{
		throw "This student is graduated or droppout!";
	}
	if (major->SearchDisciplineByYearAndName(year, NameOfDiscipline))
	{
		disciplines.PushBack(major->GetDisciplineByYearAndName(year, name));
		grades.PushBack(1);
	}
	else
	{
		throw "Student can't be enrolled in that discipline";
	}
}
void Student::Advance()
{
	for (int i = 0; i < major->GetDisciplinesVector(year + 1).Size(); i++)
	{
		disciplines.PushBack(major->GetDisciplinesVector(year + 1)[i]);
	}
	++this->year;
}
void Student::Report()
{
	cout << "Exams successfully taken:";
	for (int i = 0; i < disciplines.Size(); i++)
	{
		if (grades[i] > 1)
		{
			disciplines[i]->Print();
			cout << "grade: " << grades[i];
		}
	}
	cout << "Exams failed:";
	for (int i = 0; i < disciplines.Size(); i++)
	{
		if (grades[i] == 1)
		{
			disciplines[i]->Print();
			cout << "grade: " << grades[i] + 1;
		}
		else if (grades[i] < 3)
		{
			disciplines[i]->Print();
			cout << "grade: " << grades[i];
		}
	}
	AverageGrade = 0;
	for (int i = 0; i < grades.Size(); i++)
	{
		AverageGrade += grades[i];
	}
	AverageGrade /= grades.Size();
}
void Student::Graduate()
{
	if (this->status == Status::dropout || this->status == Status::graduated)
	{
		throw "This student is graduated or droppout!";
	}
	for (int i = 0; i < grades.Size(); i++)
	{
		if (grades[i] == 1 || grades[i] < 3)
		{
			throw "This student can not be checked as graduated!";
		}
	}
	this->status = Status::graduated;
	this->group = 0;
	this->year = 0;
}
void Student::Interrupt()
{
	if (this->status == Status::graduated)
	{
		throw "This student has graduated.";
	}
	this->status = Status::dropout;
}
void Student::Resume()
{
	if (this->status == Status::enrolled)
	{
		throw "This student is already enrolled.";
	}
	if (this->status == Status::graduated)
	{
		throw "This student has graduated.";
	}
	this->status = Status::enrolled;
}
void Student::AddGrade(char* DisciplineName, double grade)
{
	if (status == Status::dropout || status == Status::graduated)
	{
		throw "This student is graduated or droppout!";
	}
	for (int i = 0; i < disciplines.Size(); i++)
	{
		if (strcmp(disciplines[i]->GetName(), name) == 0 && disciplines[i] == 0)
		{
			throw "This student hasn't been enrolled in that discipline!";
		}
		else if (strcmp(disciplines[i]->GetName(), name) == 1 || strcmp(disciplines[i]->GetName(), name) == -1)
		{
			throw "There is no discipline with that name!";
		}
		else
		{
			grades[i] = grade;
		}
	}
	AverageGrade = 0;
	for (int i = 0; i < grades.Size(); i++)
	{
		AverageGrade += grades[i];
	}
	AverageGrade /= grades.Size();
}
void Student::ChangeProgram(Major* major)
{
	if (this->status == Status::dropout || this->status == Status::graduated)
	{
		throw "This student is graduated or droppout!";
	}
	bool flag = 0;
	int counter = 0;
	int counter2 = 0;
	for (int i = 0; i < year; i++)
	{
		for (int j = 0; j < major->GetDisciplinesVector(i).Size(); j++)
		{
			if (major->GetDisciplinesVector(i)[j]->GetType() == Type::mandatory)
			{
				counter++;
			}
		}
	}
	for (int i = 0; i < year; i++)
	{
		for (int j = 0; j < major->GetDisciplinesVector(i).Size(); j++)
		{
			if (major->GetDisciplinesVector(i)[j]->GetType() == Type::mandatory)
			{
				for (int k = 0; k < disciplines.Size(); k++)
				{
					if (disciplines[k] == major->GetDisciplinesVector(i)[j])// counterite proverqvat dali vsichki zadaljitelni izpiti prisastvat i v dvata majora
					{
						counter2++;
					}
				}
			}
		}
	}
	if (counter != counter2)
	{
		throw "Тhe action cannot be performed.";
	}
	for (int i = 0; i < year; i++)
	{
		for (int j = 0; j < major->GetDisciplinesVector(i).Size(); j++)
		{
			if (major->GetDisciplinesVector(i)[j]->GetType() == Type::mandatory)
			{
				for (int k = 0; k < disciplines.Size(); k++)
				{
					if (disciplines[k] == major->GetDisciplinesVector(i)[j] && grades[k] < 3)// proverqva dali vsichki zaduljitelni izpiti sa vzeti
					{
						throw "Тhe action cannot be performed.";
					}
				}
			}
		}
	}
	for (int i = 0; i < major->GetDisciplinesVector(year).Size(); i++)
	{
		disciplines.PushBack(major->GetDisciplinesVector(year)[i]);
		if (major->GetDisciplinesVector(year)[i]->GetType() == Type::mandatory)
			grades.PushBack(1);
		else
			grades.PushBack(0);
	}
}
void Student::ChandeGroup(unsigned int group)
{
	if (this->status == Status::dropout || this->status == Status::graduated)
	{
		throw "This student is graduated or droppout!";
	}
	this->group = group;
}
void Student::ChangeYear(unsigned int year)
{
	if (this->status == Status::dropout || this->status == Status::graduated)
	{
		throw "This student is graduated or droppout!";
	}
	int count = 0;
	if (this->year + 1 == year)
	{
		for (int i = 0; i < disciplines.Size(); i++)
		{
			if (grades[i] >= 1 && grades[i] < 3)
			{
				count++;
			}
		}
		if (count > 2)
		{
			throw "Тhe action cannot be performed.";
		}
	}
	for (int i = 0; i < major->GetDisciplinesVector(year).Size(); i++)
	{
		this->disciplines.PushBack(major->GetDisciplinesVector(year)[i]);
		if (major->GetDisciplinesVector(year)[i]->GetType() == Type::mandatory)
		{
			grades.PushBack(1);//zaduljitelni zapisani
		}
		else
		{
			grades.PushBack(0);//optionalni i nezapisani
		}
	}
}
void Student::WriteStudent(ofstream& f)
{
	int strLen = strlen(name);
	f.write((const char*)&strLen, sizeof(int));
	f.write(name, strLen);
	f.write((const char*)&FacultyNumber, sizeof(unsigned int));
	f.write((const char*)&year, sizeof(unsigned int));
	f.write((const char*)&majorName, sizeof(MajorName));
	f.write((const char*)&major, sizeof(Major*));
	f.write((const char*)&group, sizeof(unsigned int));
	f.write((const char*)&status, sizeof(Status));
	f.write((const char*)&AverageGrade, sizeof(double));
	int disLen = disciplines.Size();
	f.write((const char*)&disLen, sizeof(int));
	f.write((const char*)&disciplines, disLen * sizeof(Discipline*));
	f.write((const char*)&grades, disLen * sizeof(double));
}

void Student::Protocol()
{
	cout << name;
	cout << " with faulty number: " << FacultyNumber;
	AverageGrade = 0;
	for (int i = 0; i < grades.Size(); i++)
	{
		AverageGrade += grades[i];
	}
	AverageGrade /= grades.Size();
	cout << " average grade: " << AverageGrade;
}