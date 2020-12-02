/*
 * Rowan Simmons
 * November 6, 2019
 * Project 3
 * Menu.cpp: Gets user input for playing or exiting game, and what characters they wish to play. Displays characters, strength points, armor, dice rolls, and the winner.
*/

#include "Menu.hpp"
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



//goes here from menu function
//plays game
//asks user to select characters, displays characters, strenghth points, armor, dice rolls, and winner
//points to character functions
void Menu::start()
{
    //seed for random roll function
    srand( static_cast<unsigned int>(time(NULL)));

    //initiliaze variables
    int character1;
    int character2;
    int player_1;
    int player_2;

    //user input for player 1
    //displays characters
    std::cout << "Player 1, pick your character by entering the character's index number: " << std::endl;
    std::cout << "1: Vampire" << std::endl;
    std::cout << "2: Barbarian" << std::endl;
    std::cout << "3: Blue Men" << std::endl;
    std::cout << "4: Medusa" << std::endl;
    std::cout << "5: Harry Potter" << std::endl;

    std::cin >> character1;
    checkInput(&character1); //validate input

    //creates new character based on user input
    if (character1 == 1)
    {
         player1 = new Vampire(1,12,1,6,1,18);//num_attack, int sides_attack, int num_defense, int sides_defense, int num_armor, int strength_points
    }
    else if (character1 == 2)
    {
         player1 = new Barbarian(2,6,2,6,0,12);
    }
    else if (character1 == 3)
    {
         player1 = new BlueMen(2,10,3,6,3,12);
    }
    else if (character1 == 4)
    {
        player1 = new Medusa(2,6,1,6,3,8);
    }
    else if (character1 == 5)
    {
        player1 = new HarryPotter(2,6,2,6,0,10);
    }

    //clears input
    std::cin.clear();
    std::cin.ignore();

    //user input for player 2
    //displays characters
    std::cout << "Player 2, pick your character by entering the character's index number: " << std::endl;
    std::cout << "1: Vampire" << std::endl;
    std::cout << "2: Barbarian" << std::endl;
    std::cout << "3: Blue Men" << std::endl;
    std::cout << "4: Medusa" << std::endl;
    std::cout << "5: Harry Potter" << std::endl;
    std::cin >> character2;

    checkInput(&character2); //validate input

    //creates new character based on user input
    if (character2 == 1)
    {
        player2 = new Vampire(1,12,1,6,1,18);//num_attack, int sides_attack, int num_defense, int sides_defense, int num_armor, int strength_points
    }
    else if (character2 == 2)
    {
        player2 = new Barbarian(2,6,2,6,0,12);
    }
    else if (character2 == 3)
    {
        player2 = new BlueMen(2,10,3,6,3,12);
    }
    else if (character2 == 4)
    {
        player2 = new Medusa(2,6,1,6,3,8);
    }
    else if (character2 == 5)
    {
        player2 = new HarryPotter(2,6,2,6,0,10);
    }

    //display player 1 and player 2 names
    std::cout << "Player 1 chose: " << player1->getName() << std::endl;
    std::cout << "Player 2 chose: " << player2->getName() << std::endl;
    std::cout << " " << std::endl; //for easier output viewing

    //plays game while both characters have strength points over 0
    while ((player1->getStrengthPoints() > 0) && (player2->getStrengthPoints() > 0))
    {
        //displays player 1 and player 2 names, and who is attacking who
        std::cout << "Player 1, " << player1->getName() << " attacks player 2, "  << player2->getName() << "...." << std::endl;
        //displays armor number
        std::cout << "Player 2 armor: " << player2->getArmor() << std::endl;
        //displays strength points
        std::cout << "Player 2 strength points: " << player2->getStrengthPoints() << std::endl;
        //std::cout << " " << std::endl;

        //dice roll
        player_1 = player1->rollAttack();
        player_2 = player2->rollDefense();

        //displays rolls
        std::cout << "player 1 (attacker) rolled: " << player_1 << std::endl;
        std::cout << "player 2 (defender) rolled: " << player_2 << std::endl;

        //reduce strength
        player2->reduceStrength(player_1, player_2);

        //checks again if both players are above 0 strength points
        if ((player1->getStrengthPoints() > 0) && (player2->getStrengthPoints() > 0))
        {

            //displays player names, and who is attacking who
            std::cout << "Player 2, " << player2->getName() << " attacks player 1, "  << player1->getName() << "...." << std::endl;
            //displays armor points
            std::cout << "Player 1 armor: " << player1->getArmor() << std::endl;
            //displays strength points
            std::cout << "Player 1 strength points: " << player1->getStrengthPoints() << std::endl;
            //std::cout << " " << std::endl;

            //dice rolls
            player_2 =player2->rollAttack();
            player_1 =player1->rollDefense();

            //displays dice rolls
            std::cout << "player 2 (attacker) rolled: " << player_2 << std::endl;
            std::cout << "player 1 (defender) rolled: " << player_1 << std::endl;

            //reduce strength
            player1->reduceStrength(player_2, player_1);
        }

        //if strength points are 0 or below, game over
        else

        {
            //displays game over
            std::cout << "Game over. " << std::endl;
        }

        //displays who won
        if (player1->getStrengthPoints() <= 0)
        {
            std::cout << "Player 2 has won!" << std::endl;
        }
        else if (player2->getStrengthPoints() <= 0)
        {
            std::cout << "Player 1 has won!" << std::endl;
        }
    }
    //free memory
    delete player1;
    delete player2;
}

//directs here from main function
//asks user for input to play or exit game, and validates input
//if user selects play, goes to start function
void Menu::menu()
{
        do
        {
        std::cout << "Would you like to play Fantasy Combat? Enter 1 to play, 2 to exit: " << std::endl;
        std::cin >> answer;
        checkAnswer(&answer); //validate input

          switch(answer)
          {
              case 1:
                  start(); //play game
                  break;
              case 2:
                  std::cout << "Goodbye." << std::endl; //exit game
                  break;
              default:
                  std::cout << "Invalid input. " << std::endl;
                  //break;
          }
          }while (answer!=2);
}

//validate answer
void Menu::checkAnswer(int *a)
{
    while (std::cin.fail() || std::cin.peek() != '\n' || *a < 1 || *a > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input. " << std::endl;
        std::cin >> *a;
    }
}

//validate character choice
void Menu::checkInput(int *a)
{
    while (std::cin.fail() || std::cin.peek() != '\n' || *a < 1 || *a > 5)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input. " << std::endl;
        std::cin >> *a;
    }
}



