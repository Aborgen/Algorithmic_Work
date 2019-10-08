#include "catch.hpp"
#include "../Percolation.h"
#include "../Coordinates.h"

#include "../../DataStructure/WeightedQuickUnionUFComp.h"

SCENARIO("Percolation of an nxn grid")
{
	using namespace Part1;
	SECTION("Percolates when all sites are open")
	{
		int n = 10;
		int numberOfSites = n * n;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, UF);
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				p.open(Coordinates(x, y));
			}
		}

		REQUIRE(p.percolates());
	}

	SECTION("Does not percolate when no sites are open")
	{
		int n = 10;
		int numberOfSites = n * n;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, UF);

		REQUIRE_FALSE(p.percolates());
	}

	SECTION("Percolates in straight line")
	{
		int n = 10;
		int numberOfSites = n * n;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, UF);

		p.open(Coordinates(5, 0));
		p.open(Coordinates(5, 1));
		p.open(Coordinates(5, 2));
		p.open(Coordinates(5, 3));
		p.open(Coordinates(5, 4));
		p.open(Coordinates(5, 5));
		p.open(Coordinates(5, 6));
		p.open(Coordinates(5, 7));
		p.open(Coordinates(5, 8));
		p.open(Coordinates(5, 9));

		REQUIRE(p.percolates());
	}	
	
	SECTION("Percolates in zigzag")
	{
		int n = 10;
		int numberOfSites = n * n;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, UF);

		p.open(Coordinates(0, 0));
		p.open(Coordinates(1, 0));
		p.open(Coordinates(1, 1));
		p.open(Coordinates(1, 2));
		p.open(Coordinates(0, 2));
		p.open(Coordinates(0, 3));
		p.open(Coordinates(0, 4));
		p.open(Coordinates(1, 4));
		p.open(Coordinates(1, 5));
		p.open(Coordinates(1, 6));
		p.open(Coordinates(0, 6));
		p.open(Coordinates(0, 7));
		p.open(Coordinates(0, 8));
		p.open(Coordinates(1, 8));
		p.open(Coordinates(1, 9));

		REQUIRE(p.percolates());
	}

	SECTION("Does not percolate in case of straight line, except one. All but essential site in final row open!")
	{
		int n = 10;
		int numberOfSites = n * n;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, UF);

		p.open(Coordinates(5, 0));
		p.open(Coordinates(5, 1));
		p.open(Coordinates(5, 2));
		p.open(Coordinates(5, 3));
		p.open(Coordinates(5, 4));
		p.open(Coordinates(5, 5));
		p.open(Coordinates(5, 6));
		p.open(Coordinates(5, 7));
		p.open(Coordinates(5, 8));
		for (int x = 0; x < n; x++) {
			if (x == 5) {
				continue;
			}

			p.open(Coordinates(x, 9));
		}

		REQUIRE_FALSE(p.percolates());
	}
}

SCENARIO("Percolation of an nxm grid")
{
	using namespace Part1;
	SECTION("Percolates when all sites are open")
	{
		int n = 7;
		int m = 10;
		int numberOfSites = n * m;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, m, UF);
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				p.open(Coordinates(x, y));
			}
		}

		REQUIRE(p.percolates());
	}

	SECTION("Does not percolate when no sites are open")
	{
		int n = 7;
		int m = 10;
		int numberOfSites = n * m;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, m, UF);

		REQUIRE_FALSE(p.percolates());
	}

	SECTION("Percolates in straight line")
	{
		int n = 7;
		int m = 10;
		int numberOfSites = n * m;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, m, UF);

		p.open(Coordinates(6, 0));
		p.open(Coordinates(6, 1));
		p.open(Coordinates(6, 2));
		p.open(Coordinates(6, 3));
		p.open(Coordinates(6, 4));
		p.open(Coordinates(6, 5));
		p.open(Coordinates(6, 6));
		p.open(Coordinates(6, 7));
		p.open(Coordinates(6, 8));
		p.open(Coordinates(6, 9));

		REQUIRE(p.percolates());
	}

	
	SECTION("Percolates in zigzag")
	{
		int n = 7;
		int m = 10;
		int numberOfSites = n * m;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, m, UF);

		p.open(Coordinates(5, 0));
		p.open(Coordinates(6, 0));
		p.open(Coordinates(6, 1));
		p.open(Coordinates(6, 2));
		p.open(Coordinates(5, 2));
		p.open(Coordinates(5, 3));
		p.open(Coordinates(5, 4));
		p.open(Coordinates(6, 4));
		p.open(Coordinates(6, 5));
		p.open(Coordinates(6, 6));
		p.open(Coordinates(5, 6));
		p.open(Coordinates(5, 7));
		p.open(Coordinates(5, 8));
		p.open(Coordinates(6, 8));
		p.open(Coordinates(6, 9));

		REQUIRE(p.percolates());
	}

	SECTION("Does not percolate in case of straight line, except one. All but essential site in final row open!")
	{
		int n = 7;
		int m = 10;
		int numberOfSites = n * m;
		DataStructure::WeightedQuickUnionUFComp UF(numberOfSites);
		Percolation p(n, m, UF);

		p.open(Coordinates(6, 0));
		p.open(Coordinates(6, 1));
		p.open(Coordinates(6, 2));
		p.open(Coordinates(6, 3));
		p.open(Coordinates(6, 4));
		p.open(Coordinates(6, 5));
		p.open(Coordinates(6, 6));
		p.open(Coordinates(6, 7));
		p.open(Coordinates(6, 8));
		for (int x = 0; x < n; x++) {
			if (x == 6) {
				continue;
			}

			p.open(Coordinates(x, 9));
		}

		REQUIRE_FALSE(p.percolates());
	}
}