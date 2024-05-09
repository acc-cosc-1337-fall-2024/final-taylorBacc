//
#include"die.h"

int Die::roll()
{
    srand(rand()*time(NULL));

    return rand() % 6 + 1;
}