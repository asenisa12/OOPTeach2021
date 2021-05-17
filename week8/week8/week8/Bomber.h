#pragma once


#include "StarShip.h"
#include "MotherShip.h"
#include <vector>
using namespace std;

class Bomber : public StarShip
{
	struct Bomb
	{
		int damage = 10;
	};

	vector<Bomb> m_bombs;
	Bomber();
public:
	Bomber(const Bomber&) = delete;
	Bomber& operator=(const Bomber&) = delete;
	void attack();
	void get_info();
	void reload_bomb();

	~Bomber();
	friend class MotherShip;

};