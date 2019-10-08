#include "catch.hpp"
#include "../Coordinates.h"

SCENARIO("Test implementation of Coordinates data type")
{
	using namespace Part1;
	SECTION("Get X and Y")
	{
		Coordinates coordinates(10, 2);
		REQUIRE(coordinates.X() == 10);
		REQUIRE(coordinates.Y() == 2);
	}

	SECTION("Equality between two Coordinates")
	{
		Coordinates a(1, 2);
		Coordinates b(1, 2);
		REQUIRE(a == b);
	}

	SECTION("Inequality between two Coordinates")
	{
		Coordinates a(1, 2);
		Coordinates b(1000, 2000);
		REQUIRE(a != b);
	}

	SECTION("Addition between two Coordinates")
	{
		Coordinates a(3, 2);
		Coordinates b(17, 18);
		Coordinates expected(20, 20);
		REQUIRE(a + b == expected);
	}

	SECTION("Subtraction between two Coordinates")
	{
		Coordinates a(100, 50);
		Coordinates b(50, 25);
		Coordinates expected(50, 25);
		REQUIRE(a - b == expected);
	}
}