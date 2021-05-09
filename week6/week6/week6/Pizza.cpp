#include "Pizza.h"
#include <iostream>
using namespace std;


Pizza::Pizza(int parts_count, int part_weight, int weight, float price, PizzaType type)
	:Food(parts_count, part_weight,  weight,  price), m_type(type)
{}


void Pizza::print_category()
{
	cout << "Pizza" << endl;
}
FoodType Pizza::category()
{
	Food::category();
	return PIZZA;
}

PizzaType Pizza::get_pizza_type()
{
	return m_type;
}