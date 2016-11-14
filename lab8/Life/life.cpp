// Tommy Lynch NDID: tlynch2
// main program for lifeboard
// life.cpp
#include<fstream>
#include<iostream>
#include "lifeboard.h"
#include<cstdlib>
#include<unistd.h>
#include<string>
void planned(Lifeboard &, char*);
void interactive(Lifeboard &);
using namespace std;

int main(int argc, char *argv[]){
  Lifeboard lifeboard;
  if (argc == 1) {
    interactive(lifeboard);
				// function to run interactive
  }
  else if (argc > 2) {
    cout << "Too many arguments\n";
  }
  else {
    planned(lifeboard, argv[1]);
  }
 				// function to run a pre determined 
				// scenario
  return 0;
}


void interactive(Lifeboard &lifeboard){
  char choice = 'a';
  int r, c;
  system("clear");
  lifeboard.print();
  while (choice != 'q'){
    cout << "a: enter coordinates where to add a new live cell\n";
    cout << "r: enter coordinates of where to remove a live cell\n";
    cout << "n: advnace one iteration\n";
    cout << "q: quit the program\n";
    cout << "p: play continuously\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice){
      case 'a':
	cout << "Enter coordinates(row column, top left is (1,1)): ";
        cin >> r >> c;
        lifeboard.newcell(r, c);
	break;
      case 'r':
	cout << "Enter coordinates(row column, top left is (1,1): ";
	cin >> r >> c;
	lifeboard.remove(r, c);
	break;
      case 'n':
	lifeboard.advance();
	break;
      case 'q':
	exit(1);
      case 'p':
	while(choice != 'q'){
	  lifeboard.advance();
	  usleep(100000);
	}
	break;
				// continuous loop until control-C
    }
  }
}


void planned(Lifeboard &lifeboard, char* s){
  char command;
  int r, c;
  ifstream ifs;
  ifs.open(s);
  if (!ifs){
    cout << "Invalid file";
    exit(1);
  }
  char j = ifs.peek(); 
  while(j!=EOF){
    ifs >> command >> r >> c;
    r+=1;
    c+=1;
				// adding one to each because the borders are 0 and 41 
   switch (command){
      case 'a':
        lifeboard.newcell(r, c);
        break;
      case 'r':
        lifeboard.remove(r, c);
        break;
      case 'n':
        lifeboard.advance();
        break;
      case 'q':
        exit(1);
      case 'p':
        while(command != 'q'){
          lifeboard.advance();
          usleep(100000);
        }
        break;
    }
   j = ifs.peek();
   }
}


