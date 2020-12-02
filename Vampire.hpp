/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Vampire.hpp: Header file for Vampire.cpp, which is a child class of Character. Sets values for Vampire character, and reduces strength.
*/

#ifndef Vampire_hpp
#define Vampire_hpp
#include "Character.hpp"
#include <string>

class Vampire : public Character
{
public:
    Vampire();
    Vampire(int, int, int, int, int, int);
    virtual void reduceStrength(int attackRoll, int defenseRoll);
    ~Vampire();
};

#endif /* Vampire_hpp */
