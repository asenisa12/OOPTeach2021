#include "Student.h"
#include <iostream>
#include <cstring>

void Student::copy(const char *name, int number, bool enrolled)
{
	if (m_name != nullptr)
		delete[] m_name;
	size_t name_size = strlen(name) + 1;


	m_name = new char[name_size];
	strcpy_s(m_name, name_size, name);

	m_numer = number;
	m_enrolled = enrolled;

}


Student::Student(const char *name, int number, bool enrolled)
{
	copy(name, number, enrolled);
}
Student::Student(const Student &other)
{
	copy(other.m_name, other.m_numer, other.m_enrolled);
}
Student& Student::operator=(const Student &other)
{
	if (this != &other)
		copy(other.m_name, other.m_numer, other.m_enrolled);

	return *this;
}
Student::~Student()
{
	if (m_name != nullptr)
		delete[] m_name;
}




void Student::print()
{
	std::cout << "name: " << m_name << " number:" << m_numer <<
		" enrolled:" << ((m_enrolled) ? "true" : "false") << std::endl;
}
