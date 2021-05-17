#include <iostream>
#include "Bomber.h"
#include "Starship.h"

#include "MotherShip.h"
int main()
{
	MotherShip *mothership = MotherShip::get_instance();

	mothership->addBomber();
	mothership->addInterceptor();
	mothership->addDropship();

	StarShip *bomber = mothership->get_at(0);
	bomber->attack();
	bomber->get_info();
	mothership->get_at(1)->get_info();
	mothership->get_at(2)->get_info();

	mothership->printInfo();
/*
	Bomber *bomber = new Bomber();
	delete bomber;
	
	Bomber b;
	StarShip *s_ptr = &b;
	StarShip &sref = b;


	StarShip *arr[2] = { new Bomber(), new Bomber() };
	arr[0]->attack();
	s_ptr->attack();

	StarShip *sship = new Bomber();

	sship->attack();

	delete sship;*/
	
	return 0;
}