// Tommy Lynch NDid: tlynch2
#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>

using namespace std;
double polarradius(double, double);
double quadrant(double, double);
double polarangle(double, double);
int main() {

  double x, y, r, a;
  int q; 
  cout << "Please enter an x coordinate: ";
  cin >> x;
  cout << "Please enter a y coordinate: ";
  cin >> y;
  r = polarradius(x,y);
  q = quadrant(x,y);
  a = polarangle(x,y);

cout << "polar coordinates: (" << r << ", " << a << ")" << endl; 
cout << "polar radius: " << r << endl;
cout << "polar angle: " << a << " radians" << endl;
  switch (q) {
    case 0: 
      cout << "Point is on the origin" << endl;
      break;
    case 1:
      cout << "quadrant: 1" << endl;
      break;
    case 2:
      cout << "quadrant: 2" << endl;
      break;
    case 3: 
      cout << "quadrant: 3" << endl;
      break;
    case 4: 
      cout << "quadrant: 4" << endl;
      break;
    case 5:
      cout << "Point is on the positive x axis" << endl;
      break;
    case 6: 
      cout << "Point is on the positive y axis" << endl;
      break;
    case 7: 
      cout << "Point is on the negative x axis" << endl;
      break;
    case 8: 
      cout << "Point is on the negative y axis" << endl;
      break;
 }
return 0;
} 

double polarangle(double x, double y) {
  double a;
    a = atan2(y,x);
    return a;
}
double polarradius(double x,double y) {
   double r;
   r = sqrt(x*x + y*y);  
   return r;
}


double quadrant(double x, double y) {
  int q;
  if (x == 0) {
     if (y == 0) {
         q = 0; // origin
         }
     if (y > 0) {
         q = 6; // positive y axis
         }
     if (y < 0) {
         q = 8; // negative y axis
     }
    }
  if (y == 0) {
    if (x > 0) {
      q = 5; // positive x axis
     }
    if (x < 0) {
      q = 7; // negative y axis
     }
   }
  if (x > 0) {
    if (y > 0) {
      q = 1; // first quadrant
      }
    if (y < 0) {
      q = 4; // fourth quadrant
      }    
     }
  if (x < 0) {
    if (y > 0) {
      q = 2; // second quadrant
     }
    if (y < 0) { 
      q = 3; // third quadrant
     }
    }
return q;
}





