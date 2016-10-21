#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {

double p, ir, mp, bal, interest, total;
int month;
cout << "What is the principal of the mortgage? ";
cin >> p;
  if (p < 0) {
    while (p < 0) {
      cout << "Error: please enter a valid number: ";
      cin >> p;
      }
    }

cout << "What is the interest rate of the mortgage? ";
cin >> ir;
  if (ir < 0) {
    while (ir < 0) {
     cout << "Error: please enter a valid number: ";
     cin >> ir;
     }
  }

cout << "What is the desired monthly mayment? ";
cin >> mp;
  if (mp < 0) {
    while (mp < 0) {
      cout << "Error: please enter a valid number: ";
      cin >> mp;
      }
    }


bal = p;
month = 1;
cout << "Month" << setw(12) << "Payment" <<setw(16) << "Interest" << setw(18) << "Balance"<< endl;
total = 0;

while (bal >= .01) {
  if (bal <= mp) {
      mp = bal;
    }
  interest = bal*(ir/1200);
  bal = bal + interest - mp;
    if (bal > p) {
      cout << "Error: monthly payment too low, balance would increase each month" << endl;
      return 0;
     }
  cout << month++ << setw(10) << "$" << setprecision(2) << fixed << mp << setw(10) << "$" << setprecision(2) << fixed << interest << setw(10) << "$" << setprecision(2) << fixed << bal << endl;
total = total + mp;
}
int years, remainder;
years = month/12;
floor(years);
remainder = month%12;
cout << "You paid a total of $" << total << " over " << years << " years and " << remainder << " months" << endl;
return 0;
}
