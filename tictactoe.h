#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
using namespace std;

class TicTacToe
{

//protected data
protected:
int gridNum[3][3];
string gridOut[6][11];
string player1Name, player2Name;
char playerChar1, playerChar2; 
vector<int> playerPoints {0,0};

//functions
public:
//public data
int tie;

//public functions
//no-arg constructor
TicTacToe()
{
  playerPoints[0] = 0;
  playerPoints[1] = 0;
  tie = 0;
  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
          gridNum[i][j] = 0;
    }
}

//this function set these values back to 0
void setTo0 (int &num1, int &num2)
{
  num1 = 0;
  num2 = 0;
}

//this function will print who won depending on the number passed by it
void printMessage(int num1, int num2)
{
  (num1 == 3 ? (cout << player1Name << " won!!" << endl) : (cout << player2Name << " won!!" << endl));
  (num1 == 3 ? (playerPoints[0]++) : (playerPoints[1]++));
}

//this function will print the score board
void printWinner() 
{
  cout << player1Name << " - " << playerPoints[0] << " pts  vs.  "  << player2Name << " - " << playerPoints[1] << " pts" << endl;
  cout << "Ties: " << tie << endl;
}

//this function will fill the matrix  with the characters to form the grid, it will also set the gridNum matrix back to 0
void gridFill()
{
   //building the grid
  for(int r = 0; r < 6; r++)
    {
      int coordinate = 1;
      //the rows 0,2,4 and 5 are made of only spaces and | characters
      if(r == 0 || r == 2 || r == 4 || r == 5)
      {
        for (int c = 0; c < 11; c++)
        {
          if (c == 3 || c == 7)
          gridOut[r][c] = "|";

          else
            gridOut[r][c] = " ";
        }
      }//..end if
        
      else
      {
          for (int c = 0; c < 11; c++)
        {
          //in rows 1 and 3 are the different ones that use the _ (underline) character instead of a space
          if(r == 1 || r == 3)
          {
            if (c == 3 || c == 7)
              gridOut[r][c] = "|";

            else
              gridOut[r][c] = "_";
          }//..end if
        }//..end small for loop
      }//..end else
    }//end big for loop

  //adding the coordinates on the grid
  int number = 49;
  for(int r =0; r < 6; r++)
    {
      for(int c = 0; c < 11; c++)
        {
          if(r == 1 || r == 3 || r==5)
          {
            if (c == 1 || c == 5 || c == 9)
            {
              gridOut[r][c] = (char)number;
              number++;
            }
          }//..end if
        }//..end second for loop
    }//..end for loop

  //setting gridNum to 0
  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
            gridNum[i][j] = 0;
    }
}//..end gridFill

//this function will print the grid to the screen
void printGrid()
{
    for(int r = 0; r < 6; r++)
    {
      for(int c = 0; c < 11; c++)
        cout << gridOut[r][c]; 
      cout<< endl;
    }
}

//this function will check who won
bool checkWinner()
{
  int num1 = 0;//variable that will hold number 1's
  int num2 = 0;//variable that will hold number 2's
  int j = 0;

  //adding diagonal from left to right
  for(int i = 0; i < 3; i++)
    {
      //for an accurate count, this function will place 1's and 2's in different variables since each represent a differen piece of the tic tac toe board
      if(gridNum[i][j] == 1)
        num1 = gridNum[i][j] + num1;
      else if(gridNum[i][j] == 2)
        num2 = gridNum[i][j] + num2;
      j++;
    }
  
  //checking if someone won
  if(num1 == 3 || num2 == 6)
  {
    printMessage(num1,num2);
    return true;
  }
    
  setTo0 (num1, num2);
  
  //adding diagonal from right to left
  int k = 3 - 1;
      for(int w = 0; w < 3; w++)
        {
          if(gridNum[w][k] == 1)
            num1 = gridNum[w][k] + num1;
          else if(gridNum[w][k] == 2)
            num2 = gridNum[w][k] + num2;
           k--;
        }

  //checking if someone won
  if(num1 == 3 || num2 == 6)
  {
    printMessage(num1,num2);
    return true;
  }
    
  setTo0 (num1, num2);

  //adding columns 
  for(int col = 0; col < 3; col++)
    {
      for(int i = 0; i < 3; i++)
        {
          if(gridNum[i][col] == 1)
            num1 = gridNum[i][col] + num1;
          else if (gridNum[i][col] == 2)
            num2 = gridNum[i][col] + num2;
        }

      //checking if someone won
      if(num1 == 3 || num2 == 6)
      {
        printMessage(num1,num2);
        return true;
      }
    setTo0 (num1, num2);
    }
  setTo0 (num1, num2);
  
  //adding rows 
  for(int row = 0; row < 3; row++)
    {
      for(int i = 0; i < 3; i++)
        {
          if(gridNum[row][i] == 1)
            num1 = gridNum[row][i] + num1;
          else if (gridNum[row][i] == 2)
            num2 = gridNum[row][i] + num2;
        }
      
      //checking is someone won
      if(num1 == 3 || num2 == 6)
      {
        printMessage(num1,num2);
        return true;
      }
      setTo0 (num1, num2);
    }//end for loop
  //if none of those retured true the function will return false meaning that none has won yet
  return false;
}//..end checkWinner

//this furnction will get the placement from the user in different ways dependong on the class
virtual void getPlacement(int player)
{
  return;
}

//menu function
  int ticTacToetMenu()
  {
    //local variable 
    int choice;
    cout << endl;
    cout << "1: One Player" << endl;
    cout << "2: Two Players" << endl;
    cout << "3: quit" << endl;

    
    cout << "Enter your selection: ";
    cin >> choice;

    while(choice != 1 && choice != 2 && choice != 3)
      {
        cout << "Invalid input, choose again: ";
        cin >> choice;
      }
    cout << endl;
    return choice;
  }

/*this function will check if the spot choosen by the user is empty, if it isn't it will keep asking for the user to place it in an empty spot */
void checkingPlacement (int player)
{
  cout << endl;
  cout << "There is already a piece here" << endl;
  cout << endl;
  getPlacement(player);
}
};//end TicTacToe

#endif
