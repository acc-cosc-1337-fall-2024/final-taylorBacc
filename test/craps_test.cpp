#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include"die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify die class") {
	bool state;
	DIE newdie;

	for(int i = 0; i < 10; i++)
	{
		int testdie = newdie.roll();
		if(testdie >= 1 && testdie <= 6)
		{
			state = true;
		}
		else
		{
			state = false;
		}
		REQUIRE(state == true);
	}
}