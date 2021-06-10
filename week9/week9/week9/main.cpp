#include <iostream>
#include "Set.h"
using namespace std;

class A
{
public:
	virtual void func() = 0;
};


class B : public A
{
public:

	void b_function()
	{

	}
	virtual void func()
	{
		///
	}
};

class C : public A
{
	int m_var;
public:
	void func_C()
	{
		m_var++;
	}
	virtual void func()
	{
		///
	}

};

void funtion(A** arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		C * c = dynamic_cast<C*>(arr[i]);
		if (c != nullptr)
		{
			// do something with c
			continue;
		}

		B * b = dynamic_cast<B*>(arr[i]);
		if (b != nullptr)
		{
			//do something with b
		}


	}
}


class Container{
	void*data;
public:
	void add_value(void* new_data)
	{
		data = new_data;
	}
};

template<typename T1, typename T2>
class TemplateConatiner
{
	T1* data1;
	T2* data2;

public:
	void add_data(T1* new_data)
	{
		data1 = new_data;
	}
};


int main()
{
	int a;
	(float)a;

	A *b = new B();

	B* casted = static_cast<B*>(b);
	//casted->func_C();
	//casted->func_C();
	//casted->b_function();

	C *c = new C();

	A* c_casted = dynamic_cast<A*>(c);
	if (c_casted == nullptr)
	{
		cout << "c_casted is nullptr" << endl;
	}
	Container container;
	container.add_value((void*)c);

	TemplateConatiner<C,B> teamplate_cont_c;
	teamplate_cont_c.add_data(c);

	TemplateConatiner<B,C> teamplate_cont_b;
	teamplate_cont_b.add_data(casted);
	
	Set<int> s;

	s.add_element(1);
	s.add_element(2);
	s.add_element(3);


	Set<int> s2;

	s2.add_element(6);
	s2.add_element(2);
	s2.add_element(7);


	Set<int> s3 = s + s2;

	for (size_t i = 0; i < s3.getSize(); i++)
	{
		cout << s3[i] << endl;
	}

	cout << endl;
	Set<int> s4 = s * s2;

	for (size_t i = 0; i < s4.getSize(); i++)
	{
		cout << s4[i] << endl;
	}


	return 0;
}