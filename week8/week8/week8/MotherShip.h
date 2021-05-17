#pragma once
#include "StarShip.h"

class MotherShip
{
	StarShip *starship[20];
	const size_t m_capacity = 20;
	size_t m_size;
	MotherShip();
public:
	MotherShip(const MotherShip&) = delete;
	MotherShip& operator=(const MotherShip&) = delete;
	
	StarShip* get_at(size_t i);
	static MotherShip* get_instance();

	void addBomber();
	void addInterceptor();
	void addDropship();


	void printInfo();

	~MotherShip();
};