#pragma once
#include "Univeresity.h"

class Subject
{
	static University *s_uni;
	int m_capacity = 0;
	int m_size = 0;
	int *m_student_numbers = nullptr;

public:
	static void add_uni( University *uni);
	void add_student(Student &student);

	static void print_not_enroled_students();

	Student &operator[](int i);
	// ToDo Add constructors and operator=
	~Subject();

};
