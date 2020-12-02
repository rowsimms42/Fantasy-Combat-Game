/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * BlueMen.cpp: Child class of Character. Sets values for BlueMen character, and reduces strength.
*/

#include "BlueMen.hpp"
#include "Character.hpp"
#include <random>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

//inherits from Character class
BlueMen::BlueMen() : Character()
{

}

//deconstructor
BlueMen::~BlueMen()
{

}

//inherits from Character class
BlueMen::BlueMen(int num_attack, int sides_attack, int num_defense, int sides_defense, int num_armor, int strength_points) : Character(num_attack, sides_attack, num_defense, sides_defense, num_armor, strength_points)
{
    //sets values
    setNumAttack(2);
    setSidesAttack(10);
    setNumDefense(3);
    setSidesDefense(6);
    setArmor(3);
    setStrengthPoints(12);
    setName("Blue Men");
}

//goes here from start function under Menu class
//takes in attack roll and defense roll and calculates damage and updated strength points
//deletes a dice for 4 points of damage
void BlueMen::reduceStrength(int attackRoll, int defenseRoll)
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
    std::cout << "Updated Blue Men strength: " << getStrengthPoints() << std::endl;
    std::cout << " " << std::endl; //for easier viewing

    //for 4 points of damage, eliminate 1 die
    if ((getStrengthPoints() <=8) && (getStrengthPoints() > 4))
    {
        setNumDefense(2); //updates to 2 dice
        std::cout << "The Blue Men updated die total: " << getNumDefense() << std::endl;
    }
    //if 8 points of damage, 2 dice are eliminated
    if (getStrengthPoints() <=4)
    {
        setNumDefense(1); //updates to 1 die
        std::cout << "The Blue Men updated die total: " << getNumDefense() << std::endl;
    }
}



