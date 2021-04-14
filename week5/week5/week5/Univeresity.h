#pragma once
#include "Student.h"

class University
{
	Student **m_students;
	int m_capacity;
	int m_size;

	void erase();
	void copy(const University &other);
public:
	University(int capacity = 10);
	
	University(const University &other);
	
	University& operator=(const University &other);

	University operator+(const University &other);
	Student& operator[](const int i);
	
	int students_count();
	void add_student(const char *name, int number);
	
	~University();

};