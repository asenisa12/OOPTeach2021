#pragma once

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
	Set();
	Set(const Set<T> &other);
	Set<T>& operator=(const Set<T> &other);

	~Set<T>();

	int getSize();

	bool contains(T& elem);
	bool add_element(T& elem);
};



template<typename T>
Set<T>::Set()
	: m_capacity(10), m_size(0)
{
	m_data = new T*[m_capacity];
}

template<typename T>
Set<T>::~Set()
{
	erase();
}

template<typename T>
int Set<T>::getSize()
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
	if (this != *other)
	{
		copy(other);
	}
	return *this;
}

template<typename T>
bool Set<T>::contains(T& elem)
{
	for (size_t i = 0; i < m_size; i++)
	{
		if(elem == *m_data[i])
			return true
	}

	return false;
}
template<typename T>
bool Set<T>::add_element(T& elem)
{
	if (contains(elem))
		return false;
	if(m_size< m_capacity)
	{
		m_data[m_size++] = new T(elem);
	}
}