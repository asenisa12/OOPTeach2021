#include "Car.h"
#include <cstring>
#include <iostream>
using namespace std;

Car::Car(const char* brand, const char number[8], const char* color)
{
	copy_strings(brand, number, color);
}


void Car::copy_strings(const char* brand, const char number[8], const char* color)
{
	m_brand = new char[strlen(brand) + 1];
	strcpy(m_brand, brand);

	strncpy(m_reg_number, number, 8);

	m_color = new char[strlen(color) + 1];
	strcpy(m_color, color);
}

void Car::copy(const Car &other)
{
	delete[] m_brand;
	delete[] m_color;
	copy_strings(other.m_brand, other.m_reg_number, other.m_color);
}


Car::Car(const Car &other)
{
	copy(other);
}

Car& Car::operator=(const Car &other)
{
	if (&other != this)
	{
		copy(other);
	}

	return *this;
}

Car::~Car()
{
	delete[] m_brand;
	delete[] m_color;
}

const char* Car::get_brand() const
{
	return m_brand;
}

const char* Car::get_reg_number() const
{
	return m_reg_number;
}

const char* Car::get_color() const
{
	return m_color;
}



void Car::set_brand(const char* brand)
{
	delete m_brand;
	m_brand = new char[strlen(brand) + 1];
	strcpy(m_brand, brand);
}

void Car::set_reg_number(const char number[8])
{
	strncpy(m_reg_number, number, 8);
}

void Car::set_color(const char* color)
{
	delete m_color;
	m_color = new char[strlen(color) + 1];
	strcpy(m_color, color);
}

void Car::print()
{
	cout << "brand: " << m_brand << ", reg Num: ";
	for (size_t i = 0; i < 8; i++)
	{
		cout << m_reg_number[i];
	}
	cout << ", color:" << m_color << endl;
}