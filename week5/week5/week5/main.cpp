#include <stdexcept>
#include <exception>
#include <iostream>
#include "Student.h"
#include "Univeresity.h"
using namespace std;
int arr[3] = { 1,2,3 };

int test_at(int i)
{
	if (i > 2 &&i<10 || i < 0) throw out_of_range("out of range");

	return arr[i];
}

int a, b;

//a+b

class A
{
	int m_a;
	int arr[10];
public:
	A(int a = 1) :m_a(a)
	{}

	A operator+(const A& other)
	{
		A tmp(other.m_a + m_a);
		return  tmp;
	}

	A operator-(const A& other)
	{
		A tmp(other.m_a - m_a);
		return  tmp;
	}

	A& operator+=(const A& other)
	{
		m_a += other.m_a;

		return *this;
	}

	A& operator-=(const A& other)
	{
		m_a += other.m_a;

		return *this;
	}

	bool operator==(const A& other)
	{
		return m_a == other.m_a;
	}

	bool operator!=(const A& other)
	{
		return !((*this) == other);
	}

	A& operator=(const A &other)
	{
		m_a = other.m_a;
		return *this;
	}

	int& operator[](int i)
	{
		return arr[i];
	}


	void print()
	{
		cout << m_a << endl;
	}
};


int main()
{

	try
	{
		cout << test_at(1) << endl;
		cout << test_at(4) << endl;
		cout << test_at(2) << endl;
	}
	catch(out_of_range &ex){
		cout << ex.what() << endl;
	}


	Student s("Gosho", 12, false);
	s.print();

	A a(10);
	A b(12);
	A c = a + b;
	c.print();

	a[10];

	University uni(2);

	uni.add_student("asdfsa", 21);
	uni.add_student("asdfsa", 21); 
	uni.add_student("asdfsa", 21);


	University uni1(2);

	uni1.add_student("gfjgfads", 21);
	uni1.add_student("gfjgfads", 21);
	uni1.add_student("gfjgfads", 21);

	University uni2 = uni1 + uni;
	for (size_t i = 0; i < uni2.students_count(); i++)
	{
		uni2[i].print();
	}


	return 0;
}