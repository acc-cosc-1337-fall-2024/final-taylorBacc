#include"roll.h"

#ifndef PHASE_H
#define PHASE_H

enum class RollOutcome{
    NATURAL,
    CRAPS,
    POINT,
    SEVEN_OUT,
    NO_POINT
};

class Phase{
    public:
        RollOutcome virtual get_outcome(Roll* roll) = 0;
};

#endif