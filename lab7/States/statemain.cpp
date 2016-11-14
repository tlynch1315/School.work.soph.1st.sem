// Tommy Lynch NDID: Tlynch2
// statemain.cpp
// driver for State class
// reads data into a vector then displays it all

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;
#include "state.h"
void displayall(vector<State> &s);
void specificstate(vector<State> &s);
void population(vector<State> &s);
void statesbyyear(vector<State> &s);
void statesbyreps(vector<State> &s);

int main() {
  ifstream ifs;
  string filename;
  string abbrev, name, capital, pop_s, year_s, reps_s;
  int pop, year, reps;
  vector<State> states;
  State state;
				// initialize strings for every attribute and 
				// integers for the ones that require ints
				// initialize a vector of class State called
				// states
				// initialize a state to pushback the vector
  cout << "Enter a data file name: ";
  cin >> filename;
  ifs.open(filename);
  if (!ifs){
    cout << "Error: file name invalid\n";
    return 1;
  }
  char c = ifs.peek();
  while(c != EOF) {
    getline(ifs, abbrev,  ',');
    getline(ifs, name,    ',');
    getline(ifs, capital, ',');
    getline(ifs, pop_s,   ',');
    getline(ifs, year_s,  ',');
    getline(ifs, reps_s,  '\n');
    pop = stoi(pop_s);
    year = stoi(year_s);
    reps = stoi(reps_s);
				// uses getline with ',' as a delimiter to get
				// a string for all of the different private 
				// attributes, then converts the population, 
				// year, and number of reps to ints using 
				// stoi
    state = State(abbrev, name, capital, pop, year, reps);
    states.push_back(state);
    c = ifs.peek();
  }

int choice = 0;
while(choice!=6){
  cout << "1: Display all information\n";
  cout << "2: Display information for a specific state\n";
  cout << "3: Display information for states above a certain population\n";
  cout << "4: Display information for states founded after a certain year\n";
  cout <<"5: Display information for states with at least n representatives\n";
  cout << "6: quit\n";
  cout << "enter choice: ";
  cin >> choice;
  switch (choice){
    case 1:
      displayall(states);
      break;
    case 2:
      specificstate(states);
      break;
    case 3:
      population(states);
      break;
    case 4:
      statesbyyear(states);
      break;
    case 5: 
      statesbyreps(states);
      break;
    case 6: 
      return 0;
    default:
      cout << "Enter a valid choice\n";
      break;
    }
}
  return 0;
}

void displayall(vector<State> &s){
  for(auto it = s.begin(); it != s.end(); ++it){
    it->print();
  }
}
				// function to display all information
void specificstate(vector<State> &s){
  string stateabbrev;
  string abbrev;
  bool valid = false;
  cout << "Enter the abbreviation of a state: ";
  cin >> stateabbrev;
  for (auto it = s.begin(); it != s.end(); ++it){
    abbrev = it->getAbbrev();
    if(stateabbrev.compare(abbrev) == 0){
      it->print();
      valid = true;
    }
  }
  if (!valid) {
    cout << "Invalid State abbreviation\n";
  }    
}
				// function to display information of a 
				// specific taste
void population(vector<State> &s){
  int pop;
  cout << "Enter a population: ";
  cin >> pop;
  for (auto it = s.begin(); it != s.end(); ++it){
    if (it->getPopulation() >= pop) {
      it->print();
    }
  }
}
				// function to display information of states
				// above a certain population
void statesbyyear(vector<State> &s){
  int year;
  cout << "Enter a year: ";
  cin >> year;
  for (auto it = s.begin(); it != s.end(); ++it){
    if (it->getYear() >= year) {
      it->print();
    }
  }
}

				// function to display states founded after
				// a certain year
void statesbyreps(vector<State> &s){
  int reps;
  cout << "Enter a numer of representatives: ";
  cin >> reps;
  for (auto it = s.begin(); it != s.end(); ++it){
    if (it->getReps() >= reps) {
      it->print();
    }
  }
}
				// function to display states with at least
				// a certain amount of representatives

