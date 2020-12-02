/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * HarryPotter.cpp: Child class of Character. Sets values for HarryPotter character, and reduces strength.
*/

#include "HarryPotter.hpp"
#include "Character.hpp"
#include <random>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

//inherits from Character class
HarryPotter::HarryPotter() : Character()
{

}

//deconstructor
HarryPotter::~HarryPotter()
{

}

//inherits from Character class
HarryPotter::HarryPotter(int num_attack, int sides_attack, int num_defense, int sides_defense, int num_armor, int strength_points) : Character(num_attack, sides_attack, num_defense, sides_defense, num_armor, strength_points)
{
    //sets values
    setNumAttack(2);
    setSidesAttack(6);
    setNumDefense(2);
    setSidesDefense(6);
    setArmor(0);
    setStrengthPoints(10);
    setName("Harry Potter");
}

//goes here from start function under Menu class
//takes in attack roll and defense roll and calculates damage and updated strength points
void HarryPotter::reduceStrength(int attackRoll, int defenseRoll)
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

    //update strength points
    setStrengthPoints(getStrengthPoints()-damage);

    //harry potter's 'Hogwarts' trumps medusa's 'Glare' once
    if (attackRoll == 100 && watchStrength==0)
    {
        std::cout << "Harry Potter escaped Medusa's glare with the spell 'Hogwarts'. His strength level jumped to 20." << std::endl;
          setStrengthPoints(20); //update strength to 20
          watchStrength++; //keeps track of if hogwarts was used
    }

    //if harry potter strength points go below 10, they jump back to 20 (once)
    if ((getStrengthPoints() <= 0) && (watchStrength<1))
    {
        std::cout << "Harry Potter has used his 'Hogwarts' charm and his strength level jumped to 20." << std::endl;
        setStrengthPoints(20); //update strength to 20
        watchStrength++; //keeps track of if hogwarts was used
    }

    //outputs updated harry potter strength
    std::cout << "Updated Harry Potter strength: " << getStrengthPoints() << std::endl;
    std::cout << " " << std::endl; //for easier viewing
}




