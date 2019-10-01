#include "catch.hpp"
#include "../QuickUnionUF.h"

SCENARIO("Testing quick-union implementation")
{
	using namespace Part1;
	SECTION("Check initialized values")
	{
		DataStructure::QuickUnionUF UF(10);
		std::vector<int> expected{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (int i = 0; i < UF.count(); i++) {
			REQUIRE(UF[i] == expected[i]);
		}
	}

	SECTION("Union")
	{
		DataStructure::QuickUnionUF UF(10);
		UF.join(0, 1);
		UF.join(5, 2);
		UF.join(7, 2);
		UF.join(3, 9);
		UF.join(5, 6);
		UF.join(0, 7);

		std::vector<int> expected{ 0, 0, 5, 3, 4, 7, 7, 0, 8, 3 };
		for (int i = 0; i < UF.count(); i++) {
			REQUIRE(UF[i] == expected[i]);
		}
	}

	SECTION("Find")
	{
		DataStructure::QuickUnionUF UF(10);
		UF.join(0, 1);
		UF.join(5, 2);
		UF.join(7, 2);
		UF.join(3, 9);
		UF.join(5, 6);
		UF.join(0, 7);

		// The values in roots represent each index's root node.
		// roots{ 0, 0, 0, 3, 4, 0, 0, 0, 8, 3 }
		// In this implementation, we know two nodes are connected if they have the same root.
		REQUIRE((UF.anyConnection(0, 1) && UF.anyConnection(0, 2) && UF.anyConnection(0, 5) && UF.anyConnection(0, 6) && UF.anyConnection(0, 7)));
		REQUIRE((UF.anyConnection(1, 0) && UF.anyConnection(1, 2) && UF.anyConnection(1, 5) && UF.anyConnection(1, 6) && UF.anyConnection(1, 7)));
		REQUIRE((UF.anyConnection(2, 0) && UF.anyConnection(2, 1) && UF.anyConnection(2, 5) && UF.anyConnection(2, 6) && UF.anyConnection(2, 7)));
		REQUIRE((UF.anyConnection(5, 0) && UF.anyConnection(5, 1) && UF.anyConnection(5, 2) && UF.anyConnection(5, 6) && UF.anyConnection(5, 7)));
		REQUIRE((UF.anyConnection(6, 0) && UF.anyConnection(6, 1) && UF.anyConnection(6, 2) && UF.anyConnection(6, 5) && UF.anyConnection(6, 7)));
		REQUIRE((UF.anyConnection(7, 0) && UF.anyConnection(7, 1) && UF.anyConnection(7, 2) && UF.anyConnection(7, 5) && UF.anyConnection(7, 6)));

		REQUIRE_FALSE(UF.anyConnection(0, 3));
		REQUIRE_FALSE(UF.anyConnection(0, 4));
		REQUIRE_FALSE(UF.anyConnection(0, 8));
		REQUIRE_FALSE(UF.anyConnection(0, 9));
	}
}