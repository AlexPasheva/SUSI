#include "ListOfAllStudents.h"
#include <iostream>
ListOfAllStudents::ListOfAllStudents(Vector<Student> students)//all students of the students in the university sorted by faculty number
{                                                             //and year
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
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (students[j].GetYear() > students[j + 1].GetYear())
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
        if (students[i].GetFacultyNumber() == FN)
            return students[i];
    }
    throw "No student with that faculty number";
}
Vector<Student> ListOfAllStudents::GetStudentsByYear(unsigned int year)
{
    Vector<Student> list;
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetMajorName() == MajorName::ComputerScience)
            list.PushBack(students[i]);
    }
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetMajorName() == MajorName::Informatics)
            list.PushBack(students[i]);
    }
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetMajorName() == MajorName::InforamtionSystems)
            list.PushBack(students[i]);
    }
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetMajorName() == MajorName::AppliedMathematics)
            list.PushBack(students[i]);
    }
    return list;
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
void ListOfAllStudents::Protocol(MajorName majorName)
{
    Vector<Student> s;
    int year1 = 0, year2 = 0, year3 = 0, year4 = 0;
    for (int i = 0; i < students.Size(); i++)
    {
        if (students[i].GetMajorName() == majorName && students[i].GetStatus() == Status::enrolled)
        {
            s.PushBack(students[i]);
            if (students[i].GetYear() == 1)
            {
                year1++;
            }
            else if (students[i].GetYear() == 2)
            {
                year2;
            }
            else if (students[i].GetYear() == 3)
            {
                year3;
            }
            else if (students[i].GetYear() == 4)
            {
                year4;
            }
        }
    }
    cout << "Students of this major that are first year:";
    for (int i = 0; i < year1; i++)
    {
        students[i].Protocol();
    }
    cout << "Students of this major that are second year:";
    for (int i = 0; i < year2; i++)
    {
        students[i].Protocol();
    }
    cout << "Students of this major that are third year:";
    for (int i = 0; i < year3; i++)
    {
        students[i].Protocol();
    }
    cout << "Students of this major that are forth year:";
    for (int i = 0; i < year4; i++)
    {
        students[i].Protocol();
    }
}
void ListOfAllStudents::Write(ofstream& file)
{
    int Len = students.Size();
    file.write((const char*)&Len, sizeof(int));
    for (int i = 0; i < Len; i++)
    {
        students[i].WriteStudent(file);
    }
}
