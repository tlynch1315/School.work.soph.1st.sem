// Tommy Lynch NDID: tlynch2
// Implementation of lifeboard class
// lifeboard.cpp
#include<cstdlib>
#include "lifeboard.h"
#include<iostream>
using namespace std;

Lifeboard::Lifeboard()
{ for (int r = 0;r < 42; r++){
    for (int c = 0; c < 42; c++){
      if (r == 0) {
        board[r][c] = '-';
      }
      else if(r == 41) {
	board[r][c] = '-';
      }
      else if (c == 0 || c == 41) {
        board[r][c] = '|';
      }
      else{
      board[r][c] = ' ';
      }
      count[r][c] = 0;
      }
    }
  }
				// array is 42 x 42 to help with the
				// calculations for the edge

Lifeboard:: ~Lifeboard(){}

void Lifeboard::getCount(){
  int cnt;
  for (int r = 1; r <=40; r++){
    for (int c = 1; c<=40; c++){
      cnt = 0;
      if (board[r][c-1] == 'x'){
        cnt+=1;
      }
      if (board[r][c+1] == 'x'){
        cnt+=1;
      }
      if (board[r-1][c-1] == 'x'){
        cnt+=1;
      }
      if (board[r-1][c] == 'x'){
        cnt+=1;
      }
      if (board[r-1][c+1] == 'x'){
        cnt+=1;
      }
      if (board[r+1][c-1] == 'x'){
        cnt+=1;
      }
      if (board[r+1][c] == 'x'){
        cnt+=1;
      }
      if (board[r+1][c+1] == 'x'){
        cnt+=1;
      }
      count[r][c] = cnt;
    }
  }
}
				// method that creates an array of ints, where
				// each value is the amount of x's surrounding
				// that position on the board
void Lifeboard::changeValue(){
  getCount();
  for (int r = 1; r <=40; r++){
    for (int c = 1; c <=40; c++){
      if (board[r][c] == 'x'){
        if (count[r][c] < 2 || count[r][c] > 3){
          board[r][c] = ' ';
        }
      }
      else{
        if (count[r][c] == 3) {
          board[r][c] = 'x';
        }
      }
    }
  }
}
				// method that changes the values of the board
				// based on the count array
void Lifeboard::newcell(int r, int c){
  if (r <= 0 || r >= 41 || c <= 0 || c >= 41){
  }
  else{
  board[r][c] = 'x';
  }
  system("clear");
  print();
  if (r <= 0 || r >= 41 || c <= 0 || c >= 41){
    cout << "Invalid dimensions\n";
  }
}
				// method that creates a new live cell given that it
				// is not on the border
void Lifeboard::remove(int r, int c){
  if (r <= 0 || r >= 41 || c <= 0 || c >= 41){
  }
  else{
  board[r][c] = ' ';
  }
  system("clear");
  print();
  if (r <= 0 || r >= 41 || c <= 0 || c >= 41){
    cout << "Invalid dimensions\n";
  }
}
				// method that destroys a live cell given that it 
				// is not on the border
void Lifeboard::advance(){
  changeValue();
  system("clear");
  print();
}
				// goes through one iteration of changing the values
				// and clearing the screen and printing new array

void Lifeboard::print(){
  for (int r = 0; r <= 41; r++){
    for (int c = 0; c <=41; c++){
      cout << board[r][c];
    }
    cout << endl;
  }
}
				// method that prints the board



