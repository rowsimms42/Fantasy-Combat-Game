/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Description: Fantasy Combat game using inheritance and polymorphism
 * main.cpp: main function. starts game, and directs to menu function
 */

#include <iostream>
#include <string>
#include "Menu.hpp"

//starts game, and goes to menu function. return 0.
int main()
{
    //creates menu object because menu is a class
    Menu m;

    //directs to menu function
    m.menu();

    return 0;
}
