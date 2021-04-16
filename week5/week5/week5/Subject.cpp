#include "Subject.h"

University *Subject::s_uni = nullptr;


void Subject::add_uni( University *uni_)
{
	s_uni = uni_;
}

void Subject::add_student(Student &student)
{
	if (m_size == m_capacity)
	{
		int *tmp = m_student_numbers;
		m_capacity = (m_capacity + 1) * 2;
		
		m_student_numbers = new int[m_capacity];
		for (size_t i = 0; i < m_size; i++)
		{
			m_student_numbers[i] = tmp[i];
		}
		delete[]tmp;
	}
	m_student_numbers[m_size++] = student.m_numer;
	student.m_enrolled = true;

}

void Subject::print_not_enroled_students()
{
	if (s_uni == nullptr)
		return;

	for (size_t i = 0; i < s_uni->students_count(); i++)
	{
		if ((*s_uni)[i].m_enrolled == false)
		{
			(*s_uni)[i].print();
		}
	}
}

Student & Subject::operator[](int i)
{
	for (size_t i = 0; i < s_uni->students_count(); i++)
	{
		if ((*s_uni)[i].m_numer == m_student_numbers[i])
			return (*s_uni)[i];
	}

}


Subject::~Subject()
{
	delete [] m_student_numbers;
}
