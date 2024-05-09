#include"roll.h"
#include"die.h"
#include<vector>
#include<iostream>

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter{

    public:
        Roll* throw_dice(Die d1, Die d2);
        void display_rolled_values();
        ~Shooter(){
            for(long unsigned int i = 0; i<rolls.size(); i++)
                {
                    delete rolls[i];
                }
        };        
    private:
        std::vector<Roll*> rolls;

};

#endif