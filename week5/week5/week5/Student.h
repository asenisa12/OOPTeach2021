#pragma once


class Subject;


class Student
{
private:
	char *m_name = nullptr;
	int m_numer = 0;
	bool m_enrolled;
	void copy(const char *name, int number, bool enrolled);
public:
	Student(const char *name = "No info", int number = 0, bool enrolled = false);
	Student(const Student &other);
	Student& operator=(const Student &other);
	void print();
	~Student();

	friend class Subject;
};