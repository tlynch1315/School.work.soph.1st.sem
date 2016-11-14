// Tommy Lynch NDID: tlynch2
// Implementation of rational class

#include "rational.h"
#include<iostream>
using namespace std;
Rational::Rational()
{ numer = 1; denom = 1;}

Rational::Rational(int num, int den)
{ if (num == 0){
    while(num == 0){
      cout << "Please enter a non zero numerator: ";
      cin >> num;
    }
  }
  if (den == 0){
    while(den == 0){
      cout << "Please enter a non zero denominator: ";
      cin >> den;
    }
  }
 numer = num; denom = den;}

Rational::~Rational() {}

int Rational::getNumer()
{ return numer;}

int Rational::getDenom()
{ return denom;}

void Rational::setNumer(int num)
{ numer = num;}

void Rational::setDenom(int den)
{ denom = den;
  if (den == 0){
    while(den == 0){
      cout << "Please enter a non zero denominator: ";
      cin >> den;
    }
  }
}

void Rational::print()
{ cout << "Numerator is: " << numer << "\nDenominator is: " << denom << endl;
  cout << numer << "/" << denom << endl;
}

Rational Rational::add(Rational x)
{ Rational z;
  z.setNumer(numer*x.getDenom() + denom*x.getNumer());
  z.setDenom(denom*x.getDenom());
  return z;
}

Rational Rational::subtract(Rational x)
{ Rational z;
  z.setNumer(numer*x.getDenom() - denom*x.getNumer());
  z.setDenom(denom*x.getDenom());
  return z;
}

Rational Rational::multiply(Rational x)
{ Rational z;
  z.setNumer(numer*x.getNumer());
  z.setDenom(denom*x.getDenom());
  return z;
}

Rational Rational::divide(Rational x)
{ Rational z;
  z.setNumer(numer*x.getDenom());
  z.setDenom(denom*x.getNumer());
  return z;
}
