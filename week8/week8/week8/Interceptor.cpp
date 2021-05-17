#include "Interceptor.h"
#include <iostream>
using namespace std;

Interceptor::Interceptor()
	:StarShip("interceptor", 10)
{}

void Interceptor::attack()
{
	cout << "Interceptor attack" << endl;
	m_attack_count++;
}

void Interceptor::get_info()
{
	StarShip::get_info();
	cout << "attack count: " << m_attack_count << endl;
}