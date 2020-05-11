#pragma once
#include "Student.h"
using namespace std;
void Help()
{
	cout << "The following commands are supported:" << endl <<
		"open <file>	 opens <file>" << endl <<
		"close			 closes currently opened file" << endl <<
		"save			 saves the currently open file" << endl <<
		"saveas <file>	 saves the currently open file in <file>" << endl <<
		"help			 prints this information" << endl <<
		"exit			 exists the program" << endl <<
		"enroll <fn> <program> <group> <name>           enrolls student in a program by group and name" << endl <<
		"advance <fn>    enrolls student in next semester" << endl <<
		"change <fn> <option> <value>        changes the course, program or group of a student" << endl <<
		"graduate <fn>   checks student as graduated" << endl <<
		"interrupt <fn>  checks student as dropout" << endl <<
		"resume < fn >   resumes students rights" << endl <<
		"print <fn>      prints all the info for the given student" << endl <<
		"printall <program> <year>      prints all the info for all students in a given year" << endl <<
		"enrollin <fn> <course>         enrolls student in given course" << endl <<
		"protocol <course>              gives protocol for a certain course" << endl <<
		"report < fn>                   gives report on the grades of a certain student" << endl <<
	    "addgrade <fn> <course> <grade>      adds grade for a given course" << endl;
}

