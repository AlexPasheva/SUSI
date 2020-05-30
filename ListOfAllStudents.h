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
};
ListOfAllStudents::ListOfAllStudents(Vector<Student> students)//all students of the students in the university sorted by faculty number
{
    int n = students.Size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (students[j].GetFacultyNumber() > students[j + 1].GetFacultyNumber())
            {
                // swap arr[j+1] and arr[i] ne
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
}
Student ListOfAllStudents::SearchByFN(unsigned int FN)
{
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetFacultyNumber()==FN)
            return students[i];
    }
    throw "No student with that faculty number";
}
Vector<Student> ListOfAllStudents::GetStudentsByYear(unsigned int year)
{
    Vector<Student> list;
    for (int i = 0; i < students.Size(); i++)
    {
	    if (students[i].GetMajorName()==ComputerScience)
            list.PushBack(students[i]);
    }
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetMajorName() == Informatics)
            list.PushBack(students[i]);
    }
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetMajorName() == InforamtionSystems)
            list.PushBack(students[i]);
    }
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetMajorName() == AppliedMathematics)
            list.PushBack(students[i]);
    }
}
void ListOfAllStudents::Enroll(unsigned int FN, Major* major, unsigned int group, char* name)
{
    Student newStudent(name, FN, 1, major, major->GetMajorName(), group, Status::enrolled);
    students.PushBack(newStudent);
}
void ListOfAllStudents::Advance(unsigned int FN)
{
    Student stud = this->SearchByFN(FN);
    stud.Advance();
}
void ListOfAllStudents::Report(unsigned int FN)
{
    Student stud = this->SearchByFN(FN);
    stud.Report();
}
void ListOfAllStudents::Graduate(unsigned int FN)
{
    Student stud = this->SearchByFN(FN);
    stud.Graduate();
}
void ListOfAllStudents::Interrupt(unsigned int FN)
{
    Student stud = this->SearchByFN(FN);
    stud.Interrupt();
}
void ListOfAllStudents::Resume(unsigned int FN)
{
    Student stud = this->SearchByFN(FN);
    stud.Resume();
}
void ListOfAllStudents::AddGrade(unsigned int FN, char* DisciplineName, double grade)
{
    Student stud = this->SearchByFN(FN);
    stud.AddGrade(DisciplineName, grade);
}
void ListOfAllStudents::ChangeProgram(unsigned int FN, Major* major)
{
    Student stud = this->SearchByFN(FN);
    stud.ChangeProgram(major);
}
void ListOfAllStudents::ChandeGroup(unsigned int FN, unsigned int group)
{
    Student stud = this->SearchByFN(FN);
    stud.ChandeGroup(group);
}
void ListOfAllStudents::ChangeYear(unsigned int FN, unsigned int year)
{
    Student stud = this->SearchByFN(FN);
    stud.ChangeYear(year);
}
