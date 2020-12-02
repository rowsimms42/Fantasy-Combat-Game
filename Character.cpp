/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Character.cpp: Parent class for Vampire, Barbarian, BlueMen, Medusa, and Harry Potter. Initializes defense and attack dice number and sides, armor points, strength points, and character name. Holds virtual attack roll and defense roll functions.
*/

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <ctime>
#include <cstdlib>

//default constructor
//initliazes variables
Character::Character()
{
    numAttack = 0;
    sidesAttack = 0;
    numDefense = 0;
    sidesDefense = 0;
    armor = 0;
    strengthPoints = 0;
    name = " ";

}

//default constructor
Character::~Character()
{

}

//6 parameter constructor for Character class
Character::Character(int num_attack, int sides_attack, int num_defense, int sides_defense, int num_armor, int strength_points)
{
    numAttack = num_attack;
    sidesAttack = sides_attack;
    numDefense = num_defense;
    sidesDefense = sides_defense;
    armor = num_armor;
    strengthPoints = strength_points;
}

//setters and getters
void Character::setNumAttack(int num_attack)
{
    numAttack = num_attack;
}

int Character::getNumAttack()
{
    return numAttack;
}

void Character::setNumDefense(int num_defense)
{
    numDefense = num_defense;
}

int Character::getNumDefense()
{
    return numDefense;
}

void Character::setSidesAttack(int sides_attack)
{
    sidesAttack = sides_attack;
}

int Character::getSidesAttack()
{
    return sidesAttack;
}

void Character::setSidesDefense(int sides_defense)
{
    sidesDefense = sides_defense;
}

int Character::getSidesDefense()
{
    return sidesDefense;
}

void Character::setArmor(int num_armor)
{
    armor = num_armor;
}

int Character::getArmor()
{
    return armor;
}

void Character::setStrengthPoints(int strength_points)
{
    strengthPoints = strength_points;
}

int Character::getStrengthPoints()
{
    return strengthPoints;
}

void Character::setName(std::string char_name)
{
    name = char_name;
}
std::string Character::getName()
{
    return name;
}

//virtual roll attack function
//goes here from start function under menu class and returns roll
int Character::rollAttack()
{
    int roll_a = 0;

    for (int i=0; i<getNumAttack(); i++) //number of attack dice
    {
        roll_a+=rand() % getSidesAttack() + 1; //random roll generator
    }

    return roll_a; //returns roll in start function under Menu class
}

//virtual roll defense function
//goes here from start function under menu class and returns roll
int Character::rollDefense()
{
    int roll_d = 0;

    for (int i=0; i<getNumDefense(); i++) //number of defense dice
    {
        roll_d+=rand() % getSidesDefense() + 1; //random roll generator
    }

    return roll_d; //returns roll in start function under Menu class
}

//reduces character strength
//blank because it is handled individually in child classes
void Character::reduceStrength(int attackRoll, int defenseRoll)
{

}




