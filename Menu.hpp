/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Menu.hpp: Header file for Menu.cpp, which gets user input for playing or exiting game, what characters they wish to play, displays characters, strength points, armor, dice rolls, and the winner. Initializes pointers to character class to create characters.
*/

#ifndef Menu_hpp
#define Menu_hpp
#include "Character.hpp"

class Menu
{
private:
    int answer;
    Character* player1; //pointer to character object
    Character* player2; //pointer to character object

public:
    void menu();
    void checkAnswer(int*); //validate input
    void checkInput(int*); //validate input
    void start();
};

#endif /* Menu_hpp */
