#include"come_out_phase.h"
#include"point_phase.h"
#include"shooter.h"

using std::cout; using std::endl;

int main() 
{
	srand(time(0));

	Die die1, die2;
	Shooter shooter;
	Roll* roll;
	roll = shooter.throw_dice(die1, die2);
	int rolled_value;

	ComeOutPhase come_out_phase;

	while(come_out_phase.get_outcome(roll) == RollOutcome::NATURAL || come_out_phase.get_outcome(roll) == RollOutcome::CRAPS)
		{
			cout<<"Rolled "<<roll->roll_value()<<" roll again"<<endl;
			roll = shooter.throw_dice(die1, die2);
		}

	cout<<"Rolled "<<roll->roll_value()<<" start of point phase\n"<<"Roll until "<<roll->roll_value()<<" or 7 is rolled"<<endl;

	int point = roll->roll_value();
	roll = shooter.throw_dice(die1, die2);

	PointPhase point_phase(point);

	while(point_phase.get_outcome(roll) != RollOutcome::SEVEN_OUT && point_phase.get_outcome(roll) != RollOutcome::POINT) //the design document said this should be seven_out and no_point, but it should actually be seven_out and point, since point should escape the loop.
		{
			cout<<"Rolled "<<roll->roll_value()<<" roll again"<<endl;
			roll = shooter.throw_dice(die1, die2);
		}

	cout<<"Rolled "<<roll->roll_value()<<" end of point phase"<<endl;

	shooter.display_rolled_values();

	return 0;
}