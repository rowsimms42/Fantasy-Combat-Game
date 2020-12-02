/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Barbarian.hpp: Header file for Barbarian.cpp, which is a child class of Character. Sets values for Barbarian character, and reduces strength.
*/

#ifndef Barbarian_hpp
#define Barbarian_hpp
#include "Character.hpp"
#include <string>

class Barbarian : public Character
{

public:
    Barbarian();
    Barbarian(int, int, int, int, int, int);
    virtual void reduceStrength(int attackRoll, int defenseRoll);
    ~Barbarian();
};

#endif /* Barbarian_hpp */
