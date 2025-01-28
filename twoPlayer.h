#ifndef ONEPLAYER_H
#define ONEPLAYER_H

#include <iostream>
#include <vector>
#include "tictactoe.h"
using namespace std;

class OnePlayer : public TicTacToe
{

//functions
public:

//no-arg constructorer
OnePlayer() : TicTacToe() {}

//this function will take the placement that the user enters, it will alternate between computer 
//and player depending the the player number passed by it in the main class
void getPlacement(int player)
{
    //initializing the local variables
    int i,j,locationNum;

  if (player == 1)
  {
    cout << "(" << player1Name << ")"<< " Enter where do you wish to place your piece(1-9): ";
  cin >> locationNum;
    while(locationNum > 9)
      {
        cout << "Placement does not exist try again:";
        cin >> locationNum;
      }
     if(locationNum == 1){
       
       if(gridNum[0][0] != 0){ checkingPlacement (player);}
       else{
          gridNum[0][0] = 1;
          gridOut[1][1] = playerChar1;}
        }
      
      else if (locationNum == 2){
        if(gridNum[0][1] != 0){ checkingPlacement (player);}
        else{
          gridNum[0][1] = 1;
          gridOut[1][5] = playerChar1;}
        }
      
      else if (locationNum == 3){
        if(gridNum[0][2] != 0){ checkingPlacement (player);}
        else{
            gridNum[0][2] = 1;
            gridOut[1][9] = playerChar1;}
        }
      
      else if (locationNum == 4){
        if(gridNum[1][0] != 0){ checkingPlacement (player);}
        else{
          gridNum[1][0] = 1;
          gridOut[3][1] = playerChar1;}
        }
        
     else if (locationNum == 5){
       if(gridNum[1][1] != 0){ checkingPlacement (player);}
       else{
          gridNum[1][1] = 1;
          gridOut[3][5] = playerChar1;}
        }
      
      else if (locationNum == 6){
        if(gridNum[1][2] != 0){ checkingPlacement (player);}
        else{
            gridNum[1][2] = 1;
            gridOut[3][9] = playerChar1;}
        }
      
      else if (locationNum == 7){
        if(gridNum[2][0] != 0){ checkingPlacement (player);}
       else{
          gridNum[2][0] = 1;
          gridOut[5][1] = playerChar1;}
        }
     else if (locationNum == 8){
       if(gridNum[2][1] != 0){checkingPlacement (player);}
       else{
            gridNum[2][1] = 1;
            gridOut[5][5] = playerChar1;}
        }
      
      else if (locationNum == 9){
        if(gridNum[2][2] != 0){checkingPlacement (player);}
       else{
          gridNum[2][2] = 1;
          gridOut[5][9] = playerChar1;}
        }
  }//..end if (player == 1)

  else if (player == 2)
  {
    cout << "Now Player2" << endl;
    //making sure that the computer is placing the character in a place where there isn't a character
     srand(time(nullptr));
     do{
        //getting the random coordinates for the computer 
        i = rand() % 3 + 0;
        j = rand() % 3 + 0;
      } while (gridNum[i][j] != 0); 
    
        gridNum[i][j] = 2;

    if(i == 0) {i = 1;}
    else if (i == 1) {i = 3;}
    else if (i == 2) {i = 5;}
    if (j == 0) {j = 1;}
    else if (j == 1) {j = 5;}
    else if (j == 2) {j = 9;}
  gridOut[i][j] = playerChar2;
  }//..end else if (player == 2)
    
}//..getPlacement(int player)

friend istream& operator >> (istream& inp, OnePlayer &input)
{
  cout << "Enter your first name: ";
  cin >> input.player1Name;
  input.player2Name = "Player2";

  cout << "Choose a charcter (X/o): ";
  cin >> input.playerChar1;
  
  while(input.playerChar1 != 'x'&& input.playerChar1 != 'X' && input.playerChar1 != 'o'&& input.playerChar1 != 'O'){
    cout << endl << "Unvalid input, enter again: choose a character (X/o) ";
    cin >> input.playerChar1;
    }

  cout << "player 2 this is your character: ";
  if (input.playerChar1 == 'X' || input.playerChar1 == 'x')
    input.playerChar2 = 'o';
  else
    input.playerChar2 = 'X';
  cout << input.playerChar2 << endl;
  return inp;
}//..end operator >>
};//end OnePlayer
#endif
