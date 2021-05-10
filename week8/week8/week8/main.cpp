#include <iostream>
#include "Bomber.h"
#include "Starship.h"
int main()
{


	Bomber *bomber = new Bomber();
	delete bomber;
	

	StarShip *sship = new Bomber();

	delete sship;
	
	return 0;
}