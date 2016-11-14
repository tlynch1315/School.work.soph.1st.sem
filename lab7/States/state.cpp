// Tommy Lynch NDID: Tlynch2
// state.cpp
// implementation of state.h
#include<iomanip>
#include "state.h"
#include<iostream>
State::State() {}

State::State(string ab, string nm, string cap, int pp, int yr, int rep){
  abbrev = ab;
  name = nm;
  capital = cap;
  pop = pp;
  year = yr;
  reps = rep;
}

State::~State() {}

void State::setAbbrev( string ab)
{ abbrev = ab;}

void State::setName(string nm)
{ name = nm;}

void State::setCapital(string cap)
{ capital = cap;}

void State::setPopulation(int pp)
{ pop = pp;}

void State::setYear(int yr)
{ year = yr;}

void State:: setReps(int rep)
{ reps = rep;}

string State::getAbbrev()
{ return abbrev;}

string State::getName()
{ return name;}

string State::getCapital()
{ return capital;}

int State::getPopulation()
{ return pop;}

int State::getYear()
{ return year;}

int State::getReps()
{ return reps;}

void State::print()
{ cout << abbrev << ", ";
  cout << setw(15) << name << ", ";
  cout << setw(15) << capital << ", ";
  cout << setw(10) << pop << ", ";
  cout << setw(4) << year << ", ";
  cout << setw(2) << reps << endl;
}

