#pragma once
#include "Student.h"

class Class
{

	Student **m_students;
	int m_student_count = 0;
	int m_students_capacity;
	void copy(const Class &other);
	void free();

public:
	Class(int capacity = 10);

	Class(const Class &other);
	Class& operator=(const Class &other);

	Student& operator[](int i);
	
	void addStudent(const char *name, int fn);
	void print();

	void removeStudentByPos(int pos);

	~Class();

};
