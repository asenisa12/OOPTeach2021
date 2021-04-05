#include "Student.h"
#include <cstring>

void Student::copy(const char *name, int fn)
{
	if (m_name != nullptr)
		delete[] m_name;
	size_t name_size = strlen(name) + 1;
	
	
	m_name = new char[name_size];
	strcpy_s(m_name, name_size, name);

	
	m_FN = fn;

}

Student::Student(const char *name, int fn)
{
	copy(name, fn);
}
Student::Student(const Student &other)
{
	copy(other.m_name, other.m_FN);
}
Student& Student::operator=(const Student &other)
{
	if(this != &other)
		copy(other.m_name, other.m_FN);

	return *this;
}
Student::~Student()
{
	if (m_name != nullptr)
		delete[] m_name;
}

const char* Student::get_name() const
{
	return m_name;
}
void Student::set_name(const char* new_name)
{
	copy(new_name, m_FN);
}

int Student::get_FN() const
{
	return m_FN;
}
void Student::set_FN(int new_FN)
{
	m_FN = new_FN;
}