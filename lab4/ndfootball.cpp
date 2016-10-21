//Tommy Lynch NDID: Tlynch2

#include<iostream>
#include"nd_data.h"
#include<iomanip>
using namespace std;

void recordyear(int [], int[], int);
void winning(int [], int, int);
void losing(int [], int, int);
void positive(int [], int [], int);
void negative(int [], int [], int);
				// Prototypes of all of the functions
int main() {
int size = sizeof(wins)/sizeof(int);
int c,year,num;
do {
  cout << "Please choose one of the following options: \n";
  cout << "1 Record for a specific year\n";
  cout << "2 For years with at least n wins\n";
  cout << "3 For years with at least n losses\n";
  cout << "4 For years with at least a record of .500\n";
  cout << "5 For years with a losing record\n";
  cout << "6 To exit\n";
  cout << "Enter your choice: ";
  cin >> c;
				// outputting all of the options
  while (c < 1 || c>6) {
    cout << "Please enter a valid number: ";
    cin >> c;
  }
				// loop that makes sure you enter a valid number
  switch (c) {
    case 1:
      cout << "Enter the year: ";
      cin >> year;
      recordyear(wins, losses, year);
      cout << endl << endl;
      break;
    case 2:
      cout << "Enter an amount of wins: ";
      cin >> num;
      winning(wins, num, size);
      cout << endl << endl;
      break;
    case 3:
      cout << "Enter an amount of losses: ";
      cin >> num;
      losing(losses, num, size);
      cout << endl << endl;
      break;
    case 4: 
      positive(wins, losses, size);
      cout << endl << endl;
      break;
    case 5:
      negative(wins, losses, size);
      cout << endl << endl;
      break;
    case 6:
      cout << "Good bye!\n";
      return 0;
  }
				// switch case for choice
				// each case runs a different function
				// endl's in each case make it more 
				// aesthetically appealing for the user
} while(c!=6);
return 0;
}

void recordyear(int wins[], int losses[], int year) {
  year-=1900;
  cout << "The record for the chosen year is: " << wins[year] << "-" <<           losses[year] << endl;
}
				// this function displays the number of wins
				// then losses in a given year
void winning(int wins[], int num, int size) {
  int year;
  cout << "The following years have at least " << num << " wins: ";
  for (int i = 0; i<size; i++) {
    if (wins[i] >= num) {
      year = i+1900;
      cout << year << setw(8);
    }
  }
}
				// this function displays the years with at
				// least a certain number of wins
void losing(int losses[], int num, int size) {
  int year;
  cout << "The following years have at least " << num << " losses: ";
  for (int i = 0; i<size; i++) {
    if (losses[i] >= num) {
      year = i+1900;
      cout << year << setw(8);
    }
  }
}
				// this function displays the years with at
				// least a certain number of losses
void positive(int wins[], int losses[], int size) {
  int year;
  cout << "The following years have a record of at least .500: ";
  for (int i = 0; i<size; i++) {
    if (wins[i] >= losses[i]) {
      year = i+1900;
      cout << year << setw(8);
    }
  }
}
				// this function displays the years with a
				// record of at least .500
void negative(int wins[], int losses[], int size) {
  int year;
  cout << "The following years have a losing record: ";
  for (int i = 0; i<size; i++) {
    if (losses[i] > wins[i]) {
      year = i + 1900;
      cout << year << setw(8);
    }
  }
}
				// this function displays the years with a
				// losing record
