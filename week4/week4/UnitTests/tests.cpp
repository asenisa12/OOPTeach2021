#define CATCH_CONFIG_MAIN
#include "catch2.h"
#include <cstring>
#include "../week4/Student.h"

TEST_CASE("test Student")
{
	SECTION("Default parameters")
	{
		Student student;
		REQUIRE(strcmp(student.get_name(), "No info") == 0);
		REQUIRE(student.get_FN() == 0);

	}

	SECTION("Custom parameters")
	{
		const char* name = "Pesho";
		int fn = 17;
		Student student(name, fn);
		REQUIRE(strcmp(student.get_name(), name) == 0);
		REQUIRE(student.get_FN() == fn);

	}


	SECTION("Copy constructor")
	{


		const char* name = "Pesho";
		int fn = 17;
		Student student1(name, fn);
		Student student2 = student1;

		REQUIRE(strcmp(student2.get_name(), name) == 0);
		REQUIRE(student2.get_FN() == fn);

	}


	SECTION("Operator= ")
	{


		const char* name = "Pesho";
		int fn = 17;
		Student student1(name, fn);
		Student student2;
		student2 = student1;

		REQUIRE(strcmp(student2.get_name(), name) == 0);
		REQUIRE(student2.get_FN() == fn);

	}

}
