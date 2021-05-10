#pragma once


class StarShip
{
protected:
	char *m_type;
	unsigned int m_weight;
public: 
	StarShip(const char *type_, unsigned int weight_);
	void print_type();
	virtual void attack() = 0;
	virtual void get_info();

	virtual ~StarShip();
};
