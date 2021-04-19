#pragma once
#include "Food.h"

enum PizzaType
{
	MARGARITA,
	MEXICANA,
	PEPPERONI,
};


class Pizza : public Food
{
	PizzaType m_type;
public:
	Pizza(int parts_count, int part_weight, int weight, float price, PizzaType type);
	virtual void print_category();
	virtual FoodType category();

	PizzaType get_pizza_type();
};

