#pragma once

#include <iostream>
using namespace std;
template<typename T>
class Set
{
private:
	T** m_data;
	int m_size;
	int m_capacity;

	void erase();
	void copy(const Set<T> &other);

public:
	Set(int capacity=10);
	Set(const Set<T> &other);
	Set<T>& operator=(const Set<T> &other);

	~Set<T>();

	int getSize() const;

	T& operator[](int i);
	bool contains(const T& elem) const;
	bool add_element(const T& elem);
	bool remove(const T& elem);

	bool operator==(const Set<T> &other);
	Set<T> operator+(const Set<T> &other);
	Set<T> operator*(const Set<T> &other);
	Set<T> operator-(const Set<T> &other);
};



template<typename T>
Set<T>::Set(int capacity)
	: m_capacity(capacity), m_size(0)
{
	m_data = new T*[m_capacity];
}

template<typename T>
Set<T>::~Set()
{
	erase();
}

template<typename T>
int Set<T>::getSize() const
{
	return m_size;
}

template<typename T>
void Set<T>::erase()
{
	for (size_t i = 0; i < m_size; i++)
	{
		delete m_data[i];
	}
	delete[] m_data;
}

template<typename T>
void Set<T>::copy(const Set<T> &other)
{
	erase();
	m_data = new T*[other.m_capacity];
	m_capacity = other.m_capacity;
	m_size = other.m_size;

	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i] = new T(*other.m_data[i]);
	}
}

template<typename T>
Set<T>::Set(const Set<T> &other)
{
	copy(other);
}

template<typename T>
Set<T>& Set<T>::operator=(const Set<T> &other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

template<typename T>
bool Set<T>::contains(const T& elem) const
{
	for (size_t i = 0; i < m_size; i++)
	{
		if (elem == *m_data[i])
			return true;
	}

	return false;
}
template<typename T>
bool Set<T>::add_element(const T& elem)
{
	if (contains(elem))
		return false;
	if(m_size < m_capacity)
	{
		m_data[m_size++] = new T(elem);
		return true;
	}
	return false;

}

template<typename T>
bool Set<T>::remove(const T& elem)
{
	
	for (size_t i = 0; i < m_size; i++)
	{
		if (elem == *m_data[i])
		{
			delete m_data[i];
			
			if(m_size - 1 != i)
				m_data[i] = m_data[m_size - 1];
			
			m_data[m_size - 1] = nullptr;
			m_size--;

			return true;
		}
	}


	return false;
}
template<typename T>
T& Set<T>::operator[](int i)
{
	return *m_data[i];
}

template<typename T>
bool Set<T>::operator==(const Set<T> &other)
{
	if (m_size != other.m_size)
		return false;

	for (size_t i = 0; i < m_size; i++)
	{
		if (m_data[i] != other.m_data[i])
			return false;
	}
	return true;
}
template<typename T>
Set<T> Set<T>::operator+(const Set<T> &other)
{

	Set<T> new_set(m_capacity + other.m_capacity);


	for (size_t i = 0; i < m_size; i++)
	{
		new_set.m_data[i] = new T(*m_data[i]);
		new_set.m_size++;
	}

	int cnt = m_size;
	for (size_t i = 0; i < other.getSize(); i++)
	{
		if (!new_set.contains(*other.m_data[i]))
		{
			new_set.m_data[cnt++] = new T(*other.m_data[i]);
			new_set.m_size++;
		}
	}

	return new_set;

}


template<typename T>
Set<T> Set<T>::operator*(const Set<T> &other)
{
	Set<T> new_set(m_capacity + other.m_capacity);
	
	int cnt = 0;
	for (size_t i = 0; i < m_size; i++)
	{
		if ( other.contains(*m_data[i]) )
		{
			new_set.m_data[cnt++] = new T(*m_data[i]);
			new_set.m_size++;
		}
	}
	return new_set;
}


template<typename T>
Set<T> Set<T>::operator-(const Set<T> &other)
{
	Set<T> new_set(m_capacity + other.m_capacity);

	int cnt = 0;
	for (size_t i = 0; i < m_size; i++)
	{
		if (!other.contains(*m_data[i]))
		{
			new_set.m_data[cnt++] = new T(*m_data[i]);
			new_set.m_size++;
		}
	}
	return new_set;
}