#pragma once
#include "StarShip.h"
#include "MotherShip.h"

class Interceptor : public StarShip
{
	unsigned int m_attack_count = 0;
	Interceptor();
public:
	Interceptor(const Interceptor&) = delete;
	Interceptor& operator=(const Interceptor&) = delete;
	virtual void attack();
	virtual void get_info();

	friend class MotherShip;
};