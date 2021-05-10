#pragma once


#include "StarShip.h"
#include <vector>
using namespace std;

class Bomber : public StarShip
{
	struct Bomb
	{
		int damage = 10;
	};

	vector<Bomb> m_bombs;
public:
	Bomber();
	void attack();
	void get_info();
	void reload_bomb();

	~Bomber();


};