#pragma once



enum FoodType{
	PIZZA,
	SALAD
};
class Food
{
protected:
	int m_parts_count;
	int m_part_weight;
	int m_weight;
	float m_price;

public:

	Food(int parts_count, int part_weight, int weight, float price);
	void print_weight();
	void consume();
	virtual void print_category() = 0; 
	virtual FoodType category() = 0;
};



