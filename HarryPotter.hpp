/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * HarryPotter.hpp: Header file for HarryPotter.cpp, which is a child class of Character. Sets values for HarryPotter character, and reduces strength.
*/

#ifndef HarryPotter_hpp
#define HarryPotter_hpp
#include "Character.hpp"
#include <string>

class HarryPotter : public Character
{
protected:
    int watchStrength = 0;
public:
    HarryPotter();
    HarryPotter(int, int, int, int, int, int);
    virtual void reduceStrength(int attackRoll, int defenseRoll);
    ~HarryPotter();
};

#endif /* HarryPotter_hpp */
