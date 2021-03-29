#include <iostream>
using namespace std;
struct A {

	int get_a() {

		return a;
	}
private:
	int a;


	void func()
	{

		this->a;
		this->func();

	}

};

class B
{

private:
	int m_a;
	int m_b;
	int m_c;
	int *mem;

	void copy(const B &other)
	{
		m_a = other.m_a;
		m_b = other.m_b;
		m_c = other.m_c;
		*mem = m_a + m_b + m_c;
	}

public:
	B(int a=0, int b=0, int c=0)
	{
		m_a = a;
		m_b = b;
		m_c = c;
		mem = new int;
		*mem = a+b+c;
	}


	B(const B &other)
	{
		copy(other);
	}

	B& operator=(const B &other)
	{
		if(this != &other)
			copy(other);
		return *this;
	}

	~B()
	{
		delete mem;
	}



	int get_a()
	{
		return m_a;
	}

	int get_b()
	{
		return m_b;
	}
	int get_c()
	{
		return m_c;
	}

	int get_mem()
	{
		return *mem;
	}

	void increase_mem_value()
	{
		*mem += 10;
	}
};

int main()
{
	A a;
	a.get_a();


	B b(1, 2, 3);
	B b1(b);

	b1 = b1;
	
	

	cout << "b   a:" << b.get_a() << " b:" << b.get_b() << " c:" << b.get_c() << " mem" << b.get_mem()<< endl;

	
	b1.increase_mem_value();

	//cout << "b   a:" << b.get_a() << " b:" << b.get_b() << " c:" << b.get_c() << " mem" << b.get_mem() << endl;
	cout << "b1  a:" << b1.get_a() << " b:" << b1.get_b() << " c:" << b1.get_c() << " mem" << b1.get_mem() << endl;

	b1 = b;
	//cout << "b1  a:" << b1.get_a() << " b:" << b1.get_b() << " c:" << b1.get_c() << endl;


	return 0;
}