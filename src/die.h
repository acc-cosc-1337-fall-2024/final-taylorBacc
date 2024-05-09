#include<stdlib.h>
#include<time.h>
#include<iostream>

#ifndef DIE_H
#define DIE_H

class Die{

    public:
    int roll();

    private:
    int sides{6};

};

#endif