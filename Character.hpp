/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Character.hpp: Header file for Character.cpp, which is the Parent class for Vampire, Barbarian, BlueMen, Medusa, and Harry Potter. Initializes defense and attack dice number and sides, armor points, strength points, and character name. Holds virtual attack roll and defense roll functions.
*/

#ifndef Character_hpp
#define Character_hpp
#include <string>

class Character
{
protected: //protected so child classes have access
    int numAttack;
    int sidesAttack;
    int numDefense;
    int sidesDefense;
    int armor;
    int strengthPoints;
    std::string name;

public:
    Character();
    Character(int, int, int, int, int, int); //6 parameter constructor

    void setNumAttack(int);
    int getNumAttack();

    void setNumDefense(int);
    int getNumDefense();

    void setSidesAttack(int);
    int getSidesAttack();

    void setSidesDefense(int);
    int getSidesDefense();

    void setArmor(int);
    int getArmor();

    void setStrengthPoints(int);
    int getStrengthPoints();

    void setName(std::string);
    std::string getName();

    virtual int rollAttack();
    virtual int rollDefense();
    virtual void reduceStrength(int attackRoll, int defenseRoll);

    ~Character();
};

#endif /* Character_hpp */

