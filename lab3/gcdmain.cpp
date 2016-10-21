// Tommy Lynch NDid: Tlynch2
#include<iostream>
#include<cmath>

using namespace std;
int gcd(int, int);
int main() {
  int a, b, c;
    cout << "Enter two numbers: ";
    cin >> a >> b;
  c = gcd(a,b);
  cout << "The greatest common divisor of " << a << " and " << b << " is: " << c << endl;

return 0;
}

int gcd(int a, int b) {
  int c, d, r;
  if (a<0) {
    a = a*(-1);
   }
  if (b<0) {
    b = b*(-1);
   }
  if (a>b) {
    a = a;
   }
  else if (b>a) {
    d = b;
    b = a;
    a = d;
  }
  r = a%b;
  while (r > 0) {
   a = b;
   b = r;
   r = a%b;
  }
  c = b;
return c;
}
  





  
