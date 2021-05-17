#pragma once
#include "MotherShip.h"
#include "StarShip.h"
#include <vector>

using namespace std;

class Dropship : public StarShip
{
	struct CombatDrone
	{
		int damage;
		void attack();
		CombatDrone(int dmg) :damage(dmg){}
	};
	vector<CombatDrone> m_drones;

	Dropship();
public:
	Dropship(const Dropship&) = delete;
	Dropship& operator=(const Dropship&) = delete;
	virtual void attack();
	virtual void get_info();

	void addDrone();

	friend class MotherShip;

};

