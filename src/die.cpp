//
#include"die.h"

int DIE::roll()
{
    srand(time(0));

    return rand() % 6 + 1;
}