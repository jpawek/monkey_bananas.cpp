/*
 * Name        : Monkey Bananas
 * Author      : Joseph Pawek
 * Description : A game where the user faces off against another monkey in a
 banana throwing fight
 * Sources Used: LIST SOURCES USED
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "CinReader.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void ClearScreen();
void GameLoop();

int main() {
  // Set up CinReader instance
  CinReader reader;
  // Create Needed Variables
  char again;
  // Seed the Random Number Generator
  srand(time(0));

  // game loop
  do {
    // Send us to the GameLoop()
    GameLoop();

    // Prompt user to see if they want to continue to play
    cout << "Would you like to play again? (Y / N)\n";
    again = toupper(reader.readChar("YNyn"));
    cout << endl;
  } while (again == 'Y');

  // Program end
  return 0;
}

void GameLoop() {
// Set up the CinReader instance
  CinReader reader;
//Informs user of how the game works
  cout << "In this game two banana throwing monkeys face off agaisnt one another."
  << endl << "You will control one of the two monkeys and have three input " <<
  "options; Grab, Throw, or Block. Good Luck." << endl << flush;
//Flushes console and waits for user input to continue
  system ("PAUSE");

  ClearScreen();

//Variable establishment
  char choice;
  int banana(0);
  int banana_cpu(0);
  int block(0);
  int block_cpu(0);
  int throwing(0);
  int throwing_cpu(0);
  int gameprogress(1);
  int cpurand;

//loops the game sequence
  do{
//Gives user status of the game each turn
    if (banana_cpu == false && banana == false )
      cout << "Neither you nor the opponent have a banana." << endl;
      else if (banana_cpu == true && banana == false)
      cout << "Your opponent has a banana, you do not." << endl;
      else if (banana_cpu == false && banana == true)
      cout << "You have a banana, the opponent does not." << endl;
      else
      cout << "Both you and the opponent have a banana." << endl;
//Provides user with action options
      cout << "Type the corresponding character for what you would like to do:\n" <<
      "\n" <<
      "\'G\'rab: grab a banana to throw on a later turn.\n" <<
      "\'T\'hrow: throw a banana if you've grabbed one.\n" <<
      "\'B\'lock: block incoming banana throws.\n" <<
      "\n";
//Restricts user input to 6 different characters
      choice = reader.readChar("GTBgtb");
//Processes user choice G and resets blocking/throwing conditions from prior turns
      if ((choice == 'G'||choice == 'g') == true && banana == false){
      banana = true;
      throwing = false;
      block = false;
      block_cpu = false;
      cout << "You grab a banana.\n";
      }
//Announces error to user, resets prior turn conditions
      else if ((choice == 'G'||choice == 'g') == true && banana == true){
      throwing = false;
      block = false;
      block_cpu = false;
      cout << "You already have a banana!\n";
      }
//Enters user into blocking state, resets prior turn conditions
      else if (choice == 'B'||choice == 'b'){
      throwing = false;
      block = true;
      block_cpu = false;
      cout << "You block from incoming attacks.\n";
      }
//Processes T, resets prior turn conditions
      else if ((choice == 'T'||choice == 't') == true && banana == true){
      throwing = true;
      block = false;
      block_cpu = false;
      cout << "You throw your banana.\n";
      }
//Enters user into blocking state, resets prior turn conditions
      else if ((choice == 'T'||choice == 't') == true && banana == false){
      cout << "You have no banana to throw!\n";
      throwing = false;
      block = false;
      block_cpu = false;
      }

      cpurand = rand() % 2;
//Ensures CPU gets a banana when it lacks one
      if ((banana == false && banana_cpu == false) || (banana == true && banana_cpu == false)){
      banana_cpu = true;
      block = false;
      cout << "Your opponent grabs a banana.\n";
//Gives user win condition and message
        if (throwing == true){
        gameprogress = false;
        cout << "You hit your opponent!\nCongratulations, you win!\n";
        }
      cout << flush;
      system ("PAUSE");
      ClearScreen();
      }
//Random case 1, CPU blocking
      else if (cpurand == 0){
      block_cpu = true;
//Removes user banana if CPU blocks and user throws
        if (throwing == true){
        banana = false;
        }
      cout << "Your opponent blocks from incoming attacks.\n" << flush;
      system ("PAUSE");
      ClearScreen();
      }
//Checks if user block condition is true and prevents CPU attack
      else if ((cpurand == 1 && banana_cpu == true) && block == true){
      block = false;
      banana_cpu = false;
      cout << "Your opponent throws a banana.\n";
      cout << "You blocked the attack!\n" << flush;
      system ("PAUSE");
      ClearScreen();
      }
//Checks if user and CPU throw at the same time
      else if ((cpurand == 1 && banana_cpu == true) && throwing == true){
      throwing = false;
      banana = false;
      banana_cpu = false;
      cout << "Your opponent throws a banana.\n";
      cout << "Your bananas collide mid air!\n" << flush;
      system ("PAUSE");
      ClearScreen();
      }
//Lose condition for user if doesn't user doesnt block incoming attack
      else if ((cpurand == 1 && banana_cpu == true) && block == false){
      gameprogress = false;
      banana_cpu = false;
      cout << "Your opponent throws a banana.\n";
      cout << "You are hit by the attack!\nGAME OVER\n" << flush;
      system ("PAUSE");
      ClearScreen();
      }
    } while (gameprogress == true);


}

void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}
