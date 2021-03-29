#pragma once

class Car
{
private:
	char* m_brand = nullptr;
	char m_reg_number[8];
	char* m_color = nullptr;

	void copy_strings(const char* brand, const char number[8], const char* color);
	void copy(const Car &other);
public:
	Car(const char* brand = "none", const char number[8] = "00000000", const char* color = "none");
	Car(const Car &other);
	Car& operator=(const Car &other);

	const char* get_brand() const;
	const char* get_reg_number() const;
	const char* get_color() const;


	void set_brand(const char* brand);
	void set_reg_number(const char number[8]);
	void set_color(const char* color);


	void print();
	~Car();



};


