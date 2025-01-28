//calling libraries
#include <iostream>
#include <vector>
#include "tictactoe.h"
#include "onePlayer.h"
#include "twoPlayer.h"
using namespace std;

//function to print the boarders
void printLine(char character)
{
  for(int i = 0; i < 25; i++)
    cout << character;
  cout << endl;
}

int main() {

  int ticTacToeChoice;
  bool done = false;
  char answer;
  printLine('=');
  cout << "WELCOME TO TIC-TAC-TOE"<< endl;
  printLine('=');

  TicTacToe ticTacToe;

  //outputting the menu function
   while(!done)
    { 
      //Asking user what they wish to check
      ticTacToeChoice = ticTacToe.ticTacToetMenu();
       printLine('+');

      switch(ticTacToeChoice)
        {
          //checking if they want to play in one player mode
          case 1:
            {
              OnePlayer game;
              cin >> game;

              //keep on running the game until the player doesn't wish to play anymore 
              do{
              int k = 0, play = 1;
              bool endGame = false;
              game.gridFill();
              game.printGrid();
                
              cout << endl;
              game.printWinner();

                //keep outputting the grid until the game ends 
              do{
                  if (play % 2 != 0)
                    k = 1;
                  else
                    k = 2;
                  game.getPlacement(k);
                  game.printGrid();
                
                if(game.checkWinner() == true) {endGame = true;}

                else
                play++; //adding to the play counter 

                if(play == 10)
                  {
                    cout << "Damn, it's a tie" << endl;
                    game.tie ++;
                  }
                } while(!endGame && play != 10);

                game.printWinner();
                
                printLine('+');
                cout << "Play again? (y/n) ";
                cin >> answer;
                 printLine('+');

                //keep asking for the input while user does not write "y" or "n" 
                while(answer != 'y'&& answer != 'Y' && answer != 'n' && answer != 'N'){
                cout << endl << "Unvalid input, enter again: do you wish to play again? (y/n) ";
                cin >> answer;
                }
              }while (answer == 'y');
            break;
            }//..end case 1

          //checking if the person wants to play in two player mode
          case 2:
            {
              TwoPlayer game;
              cin >> game;

              //keep on running the game until the player doesn't wish to play anymore
              do
              {
                int k = 0, play = 1;
                bool endGame = false;
                game.gridFill();
                game.printGrid();

              cout << endl;
              game.printWinner();

                //keep outputting the grid until the game ends
                 do{
                  if (play % 2 != 0)
                    k = 1;
                  else
                    k = 2;
                  game.getPlacement(k);
                  game.printGrid();

                  if(game.checkWinner() == true) {endGame = true;}

                  else
                  play++;
                   
                   if(play == 10)
                  {
                    cout << "Damn, it's a tie" << endl;
                    game.tie ++;  
                  }
                } while(!endGame && play != 10);
                
                game.printWinner();
                
                printLine('+');
                cout << "Play again? (y/n) ";
                cin >> answer;
                printLine('+');

                //keep asking for the input while user does not write "y" or "n" 
                while(answer != 'y'&& answer != 'Y' && answer != 'n'&& answer != 'N'){
                cout << endl << "Unvalid input, enter again: do you wish to play again? (y/n) ";
                cin >> answer;
                }  
              }while(answer == 'y' || answer ==  'Y');             
            break;
            }//..end case 2

          case 3:
            {
              cout << "-- THANK YOU FOR USING THE TIC-TAC-TOE APP--" << endl;
              done = true;
              break;
            }//..end case 3
        }//..end switch
    }//end while
}//..end main
