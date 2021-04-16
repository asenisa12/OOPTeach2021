#pragma once
#include <stdexcept>

//make cpp file !!!

class Point
{
public:
	int X;
	int Y;
	Point(int x, int y):X(x), Y(y)
	{}

	Point operator+(Point &other)
	{
		return Point(X + other.X, Y + other.Y);
	}

	Point& operator+=(Point &other)
	{
		X += other.X; 
		Y += other.Y;

		return *this;
	}
};




class PointArrayCreator;

class PointArray
{
	Point **m_points;
	int m_capacity = 0;
	int m_size = 0;
	static size_t s_capacity;
	PointArray(){
		m_capacity = s_capacity;

		m_points = new Point*[m_capacity];
	}
public:
	void addPoint(int X, int Y)
	{
		if (m_capacity > m_size)
		{
			m_points[m_size++] = new Point(X, Y);
		}
	}
	Point& operator[](int i)
	{
		return *m_points[i];
	}
	Point& at(int i)
	{
		if(i>=0 && i<m_size)
			return *m_points[i];
		else throw std::out_of_range("out of PointArray Range");
	}

	int size()
	{
		return m_size;
	}

	PointArray& operator+=(const PointArray& other)
	{
		for (size_t i = 0; i < other.m_size && i< m_size; i++)
		{
			*m_points[i] += *other.m_points[i];
		}
	}

	~PointArray()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			delete m_points[i];
		}
		delete [] m_points;
	}
	friend class PointArrayCreator;
};

size_t PointArray::s_capacity = 10;



void print_num()
{
	static int num = 0;

	//cout << num++ << endl;
}

//print_num() //prints 1
//print_num() //prints 2
//print_num() //prints 1

class PointArrayCreator
{
	PointArrayCreator(int a)
	{}

public: 
	PointArrayCreator(PointArrayCreator &other) = delete;
	PointArrayCreator& operator=(PointArrayCreator &other) = delete;

	static PointArrayCreator& get_instance()
	{
		static PointArrayCreator pArrCreator(5);

		return pArrCreator;
	}
	PointArray *create_array()
	{
		return new PointArray();
	}
};