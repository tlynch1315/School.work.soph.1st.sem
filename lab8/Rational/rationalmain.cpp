// Tommy Lynch NDID: Tlynch2
// Adapted from code on Fund Comp website
// simple driver to test the Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b, c, s, d, p, q;
  
  cout << "Getting values for b: ";
  cin >> b;
				    // uses overloaded input
  cout << "*** display a and b ***\n";
  cout << "a is : " << a << endl;
  cout << "b is : " << b << endl;
  cout << "*** display c ***\n";
  cout << "c is : " << c << endl;;  // recall that c was instantiated with
				    // the default constructor

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a + b;
  cout << "a + b : " << s << endl;
  
  // subtract b from a
  cout <<"***compute d as the math difference of a and b, and display d***\n";
  d = a - b;
  cout << "a - b : " << d << endl;

  // multiply a and b
  cout <<"***compute p as the math product of a and b, and display p***\n";
  p = a * b;
  cout << "a * b : " << p << endl;

  // divide a by b
  cout << "***compute q as the math quotient of a divided by b and display q***\n";
  q = a / b;
  cout << "a / b : " << q << endl;
  return 0;
}

