#include "MotherShip.h"
#include "Bomber.h"
#include "Interceptor.h"
#include "Dropship.h"
#include <iostream>
using namespace std;


MotherShip::MotherShip()
{

}
StarShip* MotherShip::get_at(size_t i)
{
	if (i < m_size)
		return starship[i];
	
	return nullptr;
}

MotherShip* MotherShip::get_instance()
{
	static MotherShip instance;

	return &instance;
}


void MotherShip::addBomber()
{
	if (m_size < m_capacity)
		starship[m_size++] = new Bomber();
}
void MotherShip::addInterceptor()
{
	if (m_size < m_capacity)
		starship[m_size++] = new Interceptor();
}
void MotherShip::addDropship()
{
	if (m_size < m_capacity)
		starship[m_size++] = new Dropship();
}

MotherShip::~MotherShip()
{
	for (size_t i = 0; i < m_size; i++)
	{
		delete starship[i];
	}
}


void MotherShip::printInfo()
{
	for (size_t i = 0; i < m_size; i++)
	{
		cout << "Ship [" << i << "]" << " info:\n";

		starship[i]->get_info();
		cout << endl;
	}
}