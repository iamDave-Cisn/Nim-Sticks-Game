// MAIN.CPP
#include <iostream>
#include "nimFunctions.hpp"
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int nimSticks = 11;
    int userSelection;
    int player;
    char keepPlaying = 'y';
    
    gameWelcomeMessage();
    
    cout << "The board currently looks like this: ";

    for (int i = 1; i <= 11; i++)
    {
       cout << "| "; //displays the board
    }
    cout << endl;

    cout << "Player one, it is your turn \n";
    
    do {
       
        while (nimSticks != 0 && keepPlaying == 'y')
        {
            
            cout << "Enter how many sticks you want to remove: ";
            cin >> userSelection;
            
            userSelection = dataValidation(userSelection);
            nimSticks = showBoard(userSelection);
            
            //swap players
            player = getMove();
            
            if (nimSticks <= 3)
                {
                    cout << "Congrats player " << player << " You win!" << endl;
                    nimSticks = 0;
                }
            else
            {
            
                if (player == 1)
                    cout << "Player one, it is your turn \n";
                else if (player == 2)
                    cout << "Player two, it is your turn \n";
            }
            
            
        }
        
        cout << "Do you want to keep playing? (y/n):  ";
        cin >> keepPlaying;
        keepPlaying = tolower(keepPlaying);
        keepPlaying = dataValidation(keepPlaying);
        nimSticks = 11;
        
    } while (playAgain(keepPlaying));
    
    endGameMessage();
    
    return 0;
}
