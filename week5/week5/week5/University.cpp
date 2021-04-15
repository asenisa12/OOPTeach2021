#include "Univeresity.h"

University::University(int capacity)
	:m_size(0), m_capacity(capacity)
{
	if (capacity > 0)
	{
		m_students = new Student*[capacity];
	}
	else
		m_students = nullptr;
	
}



void University::erase()
{
	for (size_t i = 0; i < m_size; i++)
	{
		delete m_students[i];
	}
	delete[] m_students;
}
void University::copy(const University &other)
{
	erase();
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_students = new Student*[other.m_capacity];
	for (size_t i = 0; i < m_size; i++)
	{
		m_students[i] = new Student(*(other.m_students[i]));
	}
}

University::University(const University &other)
{
	copy(other);
}

University& University::operator=(const University &other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

University University::operator+(const University &other)
{
	University tmp(m_capacity + other.m_capacity);
	for (size_t i = 0; i < m_size; i++)
	{
		tmp.m_students[tmp.m_size++] = new Student(*m_students[i]);
	}

	for (size_t i = 0; i < other.m_size; i++)
	{
		tmp.m_students[tmp.m_size++] = new Student(*other.m_students[i]);
	}

	return tmp;
}


void University::add_student(const char *name, int number)
{
	if (m_size >= m_capacity)
	{
		m_capacity *= 2;
		Student **tmp =  new Student*[m_capacity];
		for (size_t i = 0; i < m_size; i++)
		{
			tmp[i] = m_students[i];
		}

		delete[]m_students;
		m_students = tmp;
	}
	m_students[m_size++] = new Student(name, m_size - 1, false);
}

Student& University::operator[](const int i)
{
	return *m_students[i];
}



int University::students_count()
{
	return m_size;
}
University::~University()
{
	erase();
}