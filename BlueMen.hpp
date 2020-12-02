/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * BlueMen.hpp: Header file for BlueMen.cpp, which is a child class of Character. Sets values for BlueMen character, and reduces strength.
*/

#ifndef BlueMen_hpp
#define BlueMen_hpp
#include "Character.hpp"
#include <string>

class BlueMen : public Character
{

public:
    BlueMen();
    BlueMen(int, int, int, int, int, int);
    virtual void reduceStrength(int attackRoll, int defenseRoll);
    ~BlueMen();

};

#endif /* BlueMen_hpp */
