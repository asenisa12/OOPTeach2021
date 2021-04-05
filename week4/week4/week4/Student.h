#pragma once


class Student
{
private:
	char *m_name = nullptr;
	int m_FN = 0;
	void copy(const char *name, int fn);
public:
	Student(const char *name = "No info", int fn = 0);
	Student(const Student &other);
	Student& operator=(const Student &other);
	~Student();
	
	const char* get_name() const ;
	void set_name(const char* new_name);

	int get_FN() const;
	void set_FN(int new_FN);

};
