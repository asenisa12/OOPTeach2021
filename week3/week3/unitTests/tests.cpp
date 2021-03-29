#define CATCH_CONFIG_MAIN
#include "catch2.h"
#include "../week3/sumator.h"
#include "../week3/Car.h"
#include <cstring>

TEST_CASE("simple test")
{
	REQUIRE(sum(5, 5) == 10);
}


TEST_CASE("Car testing")
{
	SECTION("Default parameters")
	{
		Car car;
		REQUIRE(strcmp(car.get_brand(), "none") == 0);
		REQUIRE(strncmp(car.get_reg_number(), "00000000", 8) == 0);
		REQUIRE(strcmp(car.get_color(), "none") == 0);

	}

	SECTION("Custom parameters")
	{

		const char* brand = "BMW";
		const char* reg_number = "CO2378HK";
		const char* color = "black";
		Car car(brand, reg_number, color);
		REQUIRE(strcmp(car.get_brand(), brand) == 0);
		REQUIRE(strncmp(car.get_reg_number(), reg_number, 8) == 0);
		REQUIRE(strcmp(car.get_color(), color) == 0);

	}


	SECTION("Copy constructor")
	{

		const char* brand = "BMW";
		const char* reg_number = "CO2378HK";
		const char* color = "black";
		Car car1(brand, reg_number, color);
		Car car2 = car1;
		REQUIRE(strcmp(car2.get_brand(), brand) == 0);
		REQUIRE(strncmp(car2.get_reg_number(), reg_number, 8) == 0);
		REQUIRE(strcmp(car2.get_color(), color) == 0);

	}


	SECTION("Operator= ")
	{

		const char* brand = "BMW";
		const char* reg_number = "CO2378HK";
		const char* color = "black";
		Car car1(brand, reg_number, color);
		Car car2;
		car2 = car1;
		REQUIRE(strcmp(car2.get_brand(), brand) == 0);
		REQUIRE(strncmp(car2.get_reg_number(), reg_number, 8) == 0);
		REQUIRE(strcmp(car2.get_color(), color) == 0);

	}


	SECTION("Operator= ")
	{

		const char* brand = "BMW";
		const char* reg_number = "CO2378HK";
		const char* color = "black";
		Car car;

		car.set_brand(brand);
		car.set_reg_number(reg_number);
		car.set_color(color);

		REQUIRE(strcmp(car.get_brand(), brand) == 0);
		REQUIRE(strncmp(car.get_reg_number(), reg_number, 8) == 0);
		REQUIRE(strcmp(car.get_color(), color) == 0);

	}
}