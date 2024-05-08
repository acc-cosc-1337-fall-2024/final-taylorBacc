#include<stdlib.h>
#include<time.h>
#include<iostream>

#ifndef DIE_H
#define DIE_H

class DIE{

    public:
    int roll();

    private:
    int sides{6};

};

#endif