/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Vampire.cpp: Child class of Character. Sets values for Vampire character, and reduces strength.
*/

#include "Vampire.hpp"
#include "Character.hpp"
#include <random>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

//inherits from character class
Vampire::Vampire() : Character()
{

}

//deconstructor
Vampire::~Vampire()
{

}

//inherits from character class
Vampire::Vampire(int num_attack, int sides_attack, int num_defense, int sides_defense, int num_armor, int strength_points) : Character(num_attack, sides_attack, num_defense, sides_defense, num_armor, strength_points)
{
    //sets values
    setNumAttack(1);
    setSidesAttack(12);
    setNumDefense(1);
    setSidesDefense(6);
    setArmor(1);
    setStrengthPoints(18);
    setName("Vampire");
}

//goes here from start function under Menu class
//takes in attack roll and defense roll and calculates damage and updated strength points
//outputs if vampire charms opponent, as well as updated strength
void Vampire::reduceStrength(int attackRoll, int defenseRoll)
{
    int charm = 0;
    int tempDamage = 0;
    int damage = 0;

    charm = rand() % 2; //random number generator for 50% chance

    //if charmed is activated, the vampire is undamaged
    if (charm == 0)
    {
        std::cout << "You have been charmed by the Vampire! No damage occurs." << std::endl;
        std::cout << " " << std::endl;
    }

    //if charm is not activated, damage occurs
    else
    {
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
        std::cout << "Updated Vampire strength: " << getStrengthPoints() << std::endl;
        std::cout << " " << std::endl; //for easier viewing
    }
}




