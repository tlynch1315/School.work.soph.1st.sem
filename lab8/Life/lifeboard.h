// Tommy Lynch NDID: Tlynch2
// Class for Conway's game of life
// lifeboard.h
#include<iostream>
using namespace std;

class Lifeboard {
  public: 
    Lifeboard();
    ~Lifeboard();
    void getCount();
    void changeValue();
    void advance(); 
    void newcell(int, int);
    void remove(int, int);
    void print();
  private:
    int count[42][42];
    char board[42][42];
};
 
