#include "catch.hpp"
#include "../QuickFindUF.h"

SCENARIO("Testing quick-find implementation")
{
	using namespace Part1;
	SECTION("Check initialized values")
	{
		DataStructure::QuickFindUF UF(10);
		std::vector<int> expected{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (int i = 0; i < UF.count(); i++) {
			REQUIRE(UF[i] == expected[i]);
		}
	}

	SECTION("Union")
	{
		const int EVEN = 0;
		const int ODD = 1;
		DataStructure::QuickFindUF UF(10);
		for (int i = 0; i < UF.count(); i++) {
			if (i % 2 == 0) {
				UF.join(EVEN, i);
			}
			else {
				UF.join(ODD, i);
			}
		}

		std::vector<int> expected{ EVEN, ODD, EVEN, ODD, EVEN, ODD, EVEN, ODD, EVEN, ODD };
		for (int i = 0; i < UF.count(); i++) {
			REQUIRE(UF[i] == expected[i]);
		}
	}

	SECTION("Find")
	{
		DataStructure::QuickFindUF UF(10);
		const int EVEN = 0;
		const int ODD = 1;
		for (int i = 0; i < UF.count(); i++) {
			if (i % 2 == 0) {
				UF.join(EVEN, i);
			}
			else {
				UF.join(ODD, i);
			}
		}

		// Evens
		REQUIRE((UF.anyConnection(0, 2) && UF.anyConnection(0, 4) && UF.anyConnection(0, 6) && UF.anyConnection(0, 8)));
		REQUIRE((UF.anyConnection(2, 0) && UF.anyConnection(2, 4) && UF.anyConnection(2, 6) && UF.anyConnection(2, 8)));
		REQUIRE((UF.anyConnection(4, 0) && UF.anyConnection(4, 2) && UF.anyConnection(4, 6) && UF.anyConnection(4, 8)));
		REQUIRE((UF.anyConnection(6, 0) && UF.anyConnection(6, 2) && UF.anyConnection(6, 4) && UF.anyConnection(6, 8)));
		REQUIRE((UF.anyConnection(8, 0) && UF.anyConnection(8, 2) && UF.anyConnection(8, 4) && UF.anyConnection(8, 6)));
		// Odds
		REQUIRE((UF.anyConnection(1, 3) && UF.anyConnection(1, 5) && UF.anyConnection(1, 7) && UF.anyConnection(1, 9)));
		REQUIRE((UF.anyConnection(3, 1) && UF.anyConnection(3, 5) && UF.anyConnection(3, 7) && UF.anyConnection(3, 9)));
		REQUIRE((UF.anyConnection(5, 1) && UF.anyConnection(5, 3) && UF.anyConnection(5, 7) && UF.anyConnection(5, 9)));
		REQUIRE((UF.anyConnection(7, 1) && UF.anyConnection(7, 3) && UF.anyConnection(7, 5) && UF.anyConnection(7, 9)));
		REQUIRE((UF.anyConnection(9, 1) && UF.anyConnection(9, 3) && UF.anyConnection(9, 5) && UF.anyConnection(9, 7)));

		REQUIRE_FALSE(UF.anyConnection(0, 1));
		REQUIRE_FALSE(UF.anyConnection(0, 3));
		REQUIRE_FALSE(UF.anyConnection(0, 5));
		REQUIRE_FALSE(UF.anyConnection(0, 7));
		REQUIRE_FALSE(UF.anyConnection(0, 9));
	}
}