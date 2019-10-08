#include "catch.hpp"
#include "../Site.h"

SCENARIO("Test implementation of Site")
{
	using namespace Part1;
	SECTION("Site's status is OPEN when opened")
	{
		Site site(0, 1, 0);
		site.open();
		REQUIRE(site.getStatus() == Site::Status::OPEN);
	}

	SECTION("Site's status is CLOSE when closed")
	{
		Site site(0, 1, 0);
		site.close();
		REQUIRE(site.getStatus() == Site::Status::FULL);
	}

	SECTION("Site maintains correct coordinates")
	{
		Site site(100, 1, 0);
		Coordinates coordinates = site.getCoordinates();
		REQUIRE(coordinates.X() == 100);
		REQUIRE(coordinates.Y() == 1);
	}
}