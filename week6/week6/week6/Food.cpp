#include <iostream>
using namespace std;
#include "Food.h"

Food::Food(int parts_count, int part_weight, int weight, float price)
	:m_parts_count(parts_count), m_part_weight(part_weight),m_weight(part_weight), m_price(price)
{}

void Food::consume()
{
	if (m_parts_count > 0)
	{
		m_weight -= m_part_weight;
		m_parts_count--;
	}
}


void Food::print_weight()
{
	cout << m_weight << endl;
}