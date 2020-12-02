/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Barbarian.cpp: Child class of Character. Sets values for Barbarian character, and reduces strength.
*/

#include "Barbarian.hpp"
#include "Character.hpp"
#include <random>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

//inherits from character class
Barbarian::Barbarian() : Character()
{

}

//deconstructor
Barbarian::~Barbarian()
{

}

//inherits from character class
Barbarian::Barbarian(int num_attack, int sides_attack, int num_defense, int sides_defense, int num_armor, int strength_points) : Character(num_attack, sides_attack, num_defense, sides_defense, num_armor, strength_points)
{
    //sets values
    setNumAttack(2);
    setSidesAttack(6);
    setNumDefense(2);
    setSidesDefense(6);
    setArmor(0);
    setStrengthPoints(12);
    setName("Barbarian");
}

//goes here from start function under Menu class
//takes in attack roll and defense roll and calculates damage and updated strength points
void Barbarian::reduceStrength(int attackRoll, int defenseRoll)
{
    int tempDamage = 0;
    int damage = 0;

    //damage = attacker’s roll - defenders roll - defender’s armor.
    tempDamage = attackRoll - defenseRoll -getArmor();

    //if damage is less than 0, it gets set back to 0
    if (tempDamage < 0)
    {
        damage = 0;
    }
    else
    {
        damage = tempDamage;
    }

    //updates strength points
    setStrengthPoints(getStrengthPoints()-damage);

    //outputs strength points
    std::cout << "Updated Barbarian strength: " << getStrengthPoints() << std::endl;
    std::cout << " " << std::endl; //for easier viewing
}




