#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include"die.h"
#include"roll.h"
#include"shooter.h"
#include"point_phase.h"
#include "come_out_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify die class") {
	bool state;
	Die newdie;

	std::cout<<"Testing die class:"<<std::endl;

	for(int i = 0; i < 10; i++)
	{
		int testdie = newdie.roll();
		std::cout<<testdie<<std::endl;
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

TEST_CASE("Verify Roll class") {
	bool state;
	Die d1, d2;
	Roll roller(d1, d2);

	std::cout<<"Testing Roll class:"<<std::endl;

	for(int i = 0; i < 10; i++)
	{

		roller.roll_dice();
		std::cout<<roller.roll_value()<<std::endl;
		if(roller.roll_value() >= 2 && roller.roll_value() <= 12)
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

TEST_CASE("Verify Shooter class") {
	bool state;
	Die d1, d2;
	Roll newRoll(d1, d2);
	Shooter newShooter;

	std::cout<<"Testing Shooter class:"<<std::endl;

	for(int i = 0; i < 10; i++)
	{

		int currentRoll = newShooter.throw_dice(d1, d2)->roll_value();
		std::cout<<currentRoll<<std::endl;
		if(currentRoll >= 2 && currentRoll <= 12)
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


TEST_CASE("Verify come_out and point phases") {
	int new_point = 4;
	Die d1, d2;
	Roll newRoll(d1, d2);
	Shooter newShooter;
	ComeOutPhase newComeOutPhase;
	PointPhase newPointPhase(new_point);
	
	for(int i = 0; i < 10; i++)
	{
		Roll* currentRoll = newShooter.throw_dice(d1,d2);

		std::cout<<"Roll : "<<currentRoll->roll_value()<<std::endl;

		//comeOutPhase

		if(currentRoll->roll_value() == 7 || currentRoll->roll_value() == 11)
		{
			REQUIRE(newComeOutPhase.get_outcome(currentRoll) == RollOutcome::NATURAL);
		}
		else if(currentRoll->roll_value() == 2 || currentRoll->roll_value() == 3 || currentRoll->roll_value() == 12)
		{
			REQUIRE(newComeOutPhase.get_outcome(currentRoll) == RollOutcome::CRAPS);
		}
		else
		{
			REQUIRE(newComeOutPhase.get_outcome(currentRoll) == RollOutcome::POINT);
		}

		//pointPhase

		if(currentRoll->roll_value() == new_point)
		{
			REQUIRE(newPointPhase.get_outcome(currentRoll) == RollOutcome::POINT);
		}
		else if(currentRoll->roll_value() == 7)
		{
			REQUIRE(newPointPhase.get_outcome(currentRoll) == RollOutcome::SEVEN_OUT);
		}
		else
		{
			REQUIRE(newPointPhase.get_outcome(currentRoll) == RollOutcome::NO_POINT);
		}
	}
}