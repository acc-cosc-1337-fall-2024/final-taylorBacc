//
#include"die.h"

int Die::roll()
{
    //srand(rand()*time(NULL));

    return rand() % sides + 1;
}