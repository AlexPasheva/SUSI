#pragma once
#include "Student.h"
class ListOfAllStudents
{
private:
	Vector<Student> students;
public:
	ListOfAllStudents(Vector<Student> students=Vector<Student>());
	Student SearchByFN(unsigned int FN);
	Vector<Student> GetStudentsByYear(unsigned int year);
    void Enroll(unsigned int FN, Major* major, unsigned int group, char* name);
    void Advance(unsigned int FN);
    void Report(unsigned int FN);
    void Graduate(unsigned int FN);
    void Interrupt(unsigned int FN);
    void Resume(unsigned int FN);
    void AddGrade(unsigned int FN, char* DisciplineName, double grade);
    void ChangeProgram(unsigned int FN, Major* major);
    void ChandeGroup(unsigned int FN, unsigned int group);
    void ChangeYear(unsigned int FN, unsigned int year);
    void Protocol(MajorName majorName);
    void Write(ofstream& file);
};

