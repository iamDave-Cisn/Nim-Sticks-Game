//  nimFunctions.cpp
#include "nimFunctions.hpp"
#include <iostream>
#include <limits> //included for defining LARGE
#include <cctype> //icluded for tolower (Y -> y)

const unsigned long LARGE = std::numeric_limits<std::streamsize>::max(); //largest number possible

using std::cout;
using std::cin;
using std::endl;


int player = 1;
int nimSticksTotal = 11;

void gameWelcomeMessage()
{
    cout << "Welcome to Nim! \n";
    cout << "Players will take turns removing 1, 2, or 3 sticks from the initial 11 \n";
    cout << "The player removing the last stick wins! \n";
    cout << endl;
    cout << endl;
    
}

void endGameMessage()
{
    cout << endl;
    cout << endl;
    cout << "Thank you for playing!" << endl;
    cout << endl;
    cout << endl;
}


int showBoard(int &nimSticksRemoval)
{
    
    nimSticksTotal -= nimSticksRemoval;
    
// * * * * * * * * * * * * * * * * * * * * * * * //
//    for (int i = 1; i <= nimSticksTotal; i++)  //
//    {                                          //
//       cout << "| "; //displays the board      //
//    }                                          //
//     return nimSticks;                         //
// * * * * * * * * * * * * * * * * * * * * * * * //
    
    for (int i = 1; i <= nimSticksTotal; i++)
    {
       cout << "| "; //displays the board
    }
    
    cout << "Total sticks left is: " << nimSticksTotal;
    cout << endl;
    cout << "How many sticks would you like to remove?";
    cout << " (1, 2, or 3) \n";
    
    return nimSticksTotal;
}

bool playAgain(char keepPlaying)
{
    
// * * * * * * * * * * * * * * * * * * * * * * * //
//    cout << "Do you want to play again?";      //
//    return true;                               //
// * * * * * * * * * * * * * * * * * * * * * * * //
    
    if (keepPlaying == 'y')
    {
        nimSticksTotal = 11;
        return true;
    }
    else
        return false; // keepPlaying == 'n'
    
}

int getMove()
{
    
    if (player == 1) //swap players
        player = 2;
    else
        player = 1;
    
    return player;
}

// ** Data Validation Functions ** //
char dataValidation(char validatingChar)
{
    while (validatingChar != 'y' && validatingChar != 'n')
    {
        cout << "Try again: ";
        cin.clear();
        cin.ignore(LARGE, END_LINE);
        cin >> validatingChar;
        validatingChar = tolower(validatingChar);
    }
    
    return validatingChar;
}

int dataValidation(int validatingNum)
{
    while (cin.fail() || validatingNum < MIN_STICKS || validatingNum > MAX_STICKS || validatingNum > nimSticksTotal)
    {
        cout << "Try again: ";
        cin.clear();
        cin.ignore(LARGE, END_LINE);
        cin >> validatingNum;
    }
    
    return validatingNum;
}
