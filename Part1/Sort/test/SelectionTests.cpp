#include <string>
#include "catch.hpp"
#include "../Selection.h"

SCENARIO("Testing of Selection Sort implementation [int]")
{
	using namespace Part1::Sort;
	SECTION("Sort obviously different ints")
	{
		Selection<int> s;
		std::vector<int> values{ 33, 2, 50, 1, 3, 13, 27, 30 };
		std::vector<int> expected{ 1, 2, 3, 13, 27, 30, 33, 50 };
		s.sort(values);

		REQUIRE(values == expected);
	}

	SECTION("Sort many repeating ints")
	{
		Selection<int> s;
		std::vector<int> values{ 1, 1, 1, 1, 2, 1, 1, 0, 2, 2, 1, 1, 0, 0, 10, 3, 2, 1, 0 };
		std::vector<int> expected{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 10 };
		s.sort(values);

		REQUIRE(values == expected);
	}
}

SCENARIO("Testing of Selection Sort implementation [string]")
{
	using namespace Part1::Sort;
	SECTION("Sort single letters")
	{
		Selection<std::string> s;
		std::vector<std::string> values{ "D", "E", "A", "D", "B", "E", "E", "F" };
		std::vector<std::string> expected{ "A", "B", "D", "D", "E", "E", "E", "F" };
		s.sort(values);

		REQUIRE(values == expected);
	}

	SECTION("Sort letters and words")
	{
		Selection<std::string> s;
		std::vector<std::string> values{ "gold", "b", "e", "helmet", "c", "a", "fe" };
		std::vector<std::string> expected{ "a", "b", "c", "e", "fe", "gold", "helmet" };
		s.sort(values);

		REQUIRE(values == expected);
	}
}