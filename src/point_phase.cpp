#include"point_phase.h"

RollOutcome PointPhase::get_outcome(Roll* roll)
{
    if(roll->roll_value() == point)
        {
            return RollOutcome::POINT;
        }
    else if(roll->roll_value() == 7)
        {
            return RollOutcome::SEVEN_OUT;
        }
    else
        {
            return RollOutcome::NO_POINT;
        }
}