#include"shooter.h"

Roll* Shooter::throw_dice(Die d1, Die d2){
    Roll* newRoll = new Roll(d1, d2);
    newRoll->roll_dice();
    rolls.push_back(newRoll);
    return newRoll;
}

void Shooter::display_rolled_values(){

    for(long unsigned int i = 0; i < rolls.size(); i++)
    {
        std::cout<<rolls[i]->roll_value()<<std::endl;
    }
}