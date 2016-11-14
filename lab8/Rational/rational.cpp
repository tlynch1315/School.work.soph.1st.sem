// Tommy Lynch NDID: tlynch2
// Implementation of rational class

#include "rational.h"
#include<iostream>
using namespace std;
Rational::Rational()
{ numer = 1; denom = 1;}

Rational::Rational(int num, int den)
{ setRational(num,den);}

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

void Rational::setRational(int num, int den)
{ setNumer(num);
  setDenom(den);
}




Rational Rational::operator+(Rational x)
{ Rational z;
  z.setNumer(numer*x.getDenom() + denom*x.getNumer());
  z.setDenom(denom*x.getDenom());
  return z;
}

Rational Rational::operator-(Rational x)
{ Rational z;
  z.setNumer(numer*x.getDenom() - denom*x.getNumer());
  z.setDenom(denom*x.getDenom());
  return z;
}

Rational Rational::operator*(Rational x)
{ Rational z;
  z.setNumer(numer*x.getNumer());
  z.setDenom(denom*x.getDenom());
  return z;
}

Rational Rational::operator/(Rational x)
{ Rational z;
  z.setNumer(numer*x.getDenom());
  z.setDenom(denom*x.getNumer());
  return z;
}

ostream& operator<< (ostream &s, Rational &r){
  s << r.getNumer() << "/" << r.getDenom();
  return s;
}

// istrean& operator >> (istream &s, Rational &r){
istream& operator>> (istream &s, Rational &r){
  int x, y;

  cout << "Enter the numerator and denominator: ";
  s >> x >> y;
  r.setRational(x,y);

  return s;
}   
