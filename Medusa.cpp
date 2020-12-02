/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Medusa.cpp: Child class of Character. Sets values for Medusa character, and reduces strength.
*/

#include "Medusa.hpp"
#include "Character.hpp"
#include <random>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

//inherits from character class
Medusa::Medusa() : Character()
{

}

//deconstructor
Medusa::~Medusa()
{

}

//inherits from character class
Medusa::Medusa(int num_attack, int sides_attack, int num_defense, int sides_defense, int num_armor, int strength_points) : Character(num_attack, sides_attack, num_defense, sides_defense, num_armor, strength_points)
{
    //sets values
    setNumAttack(2);
    setSidesAttack(6);
    setNumDefense(1);
    setSidesDefense(6);
    setArmor(3);
    setStrengthPoints(8);
    setName("Medusa");
}

//goes here from start function under Menu class
//overrides roll attack function from character class to accomodate glare
int Medusa::rollAttack()
{
    int sum = 0;

    int die1=0;
    int die2=0;

    die1 = rand() % getSidesAttack()+1;
    die2 = rand() % getSidesAttack()+1;

    sum = die1+die2;

    //if medusa rolls a 12, she turns her target to stone and they die
    if (sum == 12)
    {
        std::cout << "Medusa's attack rolled a 12. She glares, and her target has been turned to stone." << std::endl;
        return 100;
    }

    //return sum;
    return sum;
}

//goes here from start function under Menu class
//takes in attack roll and defense roll and calculates damage and updated strength points
void Medusa::reduceStrength(int attackRoll, int defenseRoll)
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
    std::cout << "Updated Medusa strength: " << getStrengthPoints() << std::endl;
    std::cout << " " << std::endl; //for easier viewing
}





