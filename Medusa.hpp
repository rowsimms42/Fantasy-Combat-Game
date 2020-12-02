/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Medusa.hpp: Header file for Medusa.cpp, which is a child class of Character. Sets values for Medusa character, and reduces strength.
*/

#ifndef Medusa_hpp
#define Medusa_hpp
#include "Character.hpp"
#include <string>

class Medusa : public Character
{

public:
    Medusa();
    Medusa(int, int, int, int, int, int);
    virtual void reduceStrength(int attackRoll, int defenseRoll);
    virtual int rollAttack(); //overrides rollAttack in Character
    ~Medusa();
};

#endif 
