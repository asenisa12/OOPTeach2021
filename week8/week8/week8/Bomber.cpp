#include "Bomber.h"

#include <iostream>
Bomber::Bomber()
	:m_bombs(10), StarShip("bomber",40)
{}

void Bomber::attack()
{
	m_bombs.pop_back();
	m_weight -= 2;
	cout << "bomber attack "<< endl;

}
void Bomber::reload_bomb()
{
	if (m_bombs.size() < 10)
	{
		m_bombs.push_back(Bomb());
	}
}
void Bomber::get_info()
{
	StarShip::get_info();
	cout << "bombs count: " << m_bombs.size() << endl;
}

Bomber::~Bomber()
{
	cout << "~Bomber()" << endl;
}