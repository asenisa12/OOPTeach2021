#include <iostream>
using namespace std;
#include "Pizza.h"
class Animal
{
private:

protected:
	int bloodType;


public:
	int legsCount;
	virtual void move() = 0;
};


class Frog : public Animal
{
public:

	void move()
	{
		cout << "jump" << endl;
	}
	void jump()
	{

	}

	void swim()
	{

	}

};

class ForestFrog : public Frog
{

	void climb()
	{
		if (legsCount)
		{

		}
	}
};
class Cat : public Animal
{
public:
	virtual void move()
	{
		cout << "walk" << endl;
	}
};




int main()
{

	Frog f;
	//f.legsCount = 0;
	ForestFrog ff;
	Cat c;

	Animal ** animal_arr = new Animal*[3];

	
	animal_arr[0] = new Frog;
	animal_arr[1] = new ForestFrog;
	animal_arr[2] = new Cat;
	Animal *a = new Cat;
	for (size_t i = 0; i < 3; i++)
	{
		animal_arr[i]->move();

	}



	Pizza p(10, 50, 500, 12.40, PEPPERONI);

	return 0;
}


