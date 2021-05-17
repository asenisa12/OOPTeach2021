#include "Dropship.h"
#include <iostream>
Dropship::Dropship()
	:StarShip("dropship", 30), m_drones(10, 2)
{

}

void Dropship::CombatDrone::attack()
{
	cout << "attack" << endl;
}

void Dropship::attack()
{
	if (m_drones.size() > 0)
	{
		m_weight -= m_drones.size();
		m_drones.clear();
		cout << "attack" << endl;
	}
}
void Dropship::get_info()
{
	StarShip::get_info();
	cout << "drones count: " << m_drones.size() << endl;
}

void Dropship::addDrone()
{
	if (m_drones.size() < 10)
	{
		m_weight++;
		m_drones.push_back(CombatDrone(2));
	}
}