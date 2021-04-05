#include "Class.h"
#include <iostream>
using namespace std;

Class::Class(int capacity)
	: m_students_capacity(capacity), m_students(nullptr)
{
	if (capacity > 0)
		m_students = new Student*[capacity];
}


void Class::copy(const Class &other)
{
	free();
	
	m_students_capacity = other.m_students_capacity;
	m_student_count = other.m_student_count;
	
	if (other.m_students_capacity > 0)
	{
		m_students = new Student*[m_students_capacity];
		for (int i = 0; i < m_student_count; i++)
		{
			m_students[i] = new Student( *(other.m_students[i]) );
		}
	}
}



Class::Class(const Class &other)
{
	copy(other);
}
Class& Class::operator=(const Class &other)
{
	if (this != &other)
		copy(other);

	return *this;
}

void Class::free()
{
	if (m_students_capacity > 0)
	{
		for (int i = 0; i < m_student_count; i++)
		{
			delete m_students[i];
		}
		delete[] m_students;
	}
}
Class::~Class()
{
	free();
	
}


void Class::addStudent(const char *name, int fn)
{
	if (m_students_capacity <= m_student_count)
	{
		Student** new_array = new Student*[m_students_capacity * 2];
		for (int i = 0; i < m_student_count; i++)
		{
			new_array[i] = m_students[i];
		}
		delete[]m_students;

		m_students = new_array;
		m_students_capacity *= 2;

	}

	m_students[m_student_count++] = new Student(name, fn);

}


void Class::print()
{
	for (int i = 0; i < m_student_count; i++)
	{
		cout << m_students[i]->get_name() << " FN:" << m_students[i]->get_FN() << endl;
	}
}


void Class::removeStudentByPos(int pos)
{
	if (pos >= 0 && pos < m_student_count)
	{
		delete m_students[pos];
		for (int i = pos + 1; i < m_student_count; i++)
		{
			m_students[i - 1] = m_students[i];
		}
		m_student_count--;
	}
}


Student& Class::operator[](int i)
{
	return *m_students[i];
}