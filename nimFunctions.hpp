
#ifndef nimFunctions_hpp
#define nimFunctions_hpp


const char END_LINE = '\n';
const int MIN_STICKS = 1, MAX_STICKS = 3;

void gameWelcomeMessage();
void endGameMessage();
int showBoard(int &nimSticksRemoval);
bool playAgain(char keepPlaying);
int getMove();

// ** Data validations ** //
int dataValidation(int validatingNum);
char dataValidation(char validatingChar);


#endif
/* nimFunctions_hpp */
