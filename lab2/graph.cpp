#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {

float x, y, ymax, xmax, ymin, xmin;
ymax = 0;
xmax = 0;
ymin = 100;
xmin = 100;
cout << "A plot of y = 10*(1+cos(x)) from x=0 to 20.0" << endl;
cout << "     X      Y" << endl;

for (x=0;x<=20.1;) {
  y = 10*(1+cos(x));
    if (y > ymax) {
      ymax = y;
      xmax = x;
     }
    if (y < ymin) {
      ymin = y;
      xmin = x;
     }
  cout << setw(5) << fixed << setprecision(2) << x << setw(8) << fixed << setprecision(2) << y;
  x = x+.1;
  ceil(y);
cout << "    ";
  for (int count = 0; count <= y; count++) {
    cout << "#";
    }
cout << endl;
}
cout << endl;
cout << "The max value for y is " << ymax << " at x = " << xmax << endl;
cout << "The min value for y is " << ymin << " at x = " << xmin << endl;
}




