#include "StarShip.h"
#include <cstring>
#include <iostream>

void StarShip::print_type()
{
	if (m_type != nullptr)
		std::cout <<"type: "<< m_type << std::endl;
}


StarShip::StarShip(const char *type_, unsigned int weight_)
	:m_weight(weight_)
{
	int type_str_len = strlen(type_);
	m_type = new char[type_str_len + 1];
	strcpy_s(m_type, type_str_len + 1, type_);

}

void StarShip::get_info()
{
	print_type();
	std::cout << "weight: " << m_weight << std::endl;

}


StarShip::~StarShip()
{
	std::cout << "~StarShip()" << std::endl;
	delete m_type;
}