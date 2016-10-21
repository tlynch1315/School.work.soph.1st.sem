// Tommy Lynch NDID: Tlynch2

#include<iostream>
#include<iomanip>

using namespace std;

float sum(float, float);
float difference(float, float);
float product(float, float);
float quotient(float, float);

int main() {
  float x, y, s, d, p, q;
  int c;
  do{
    cout << "What operation would you like to do?" << endl;
    cout << "1 for addition" << endl;
    cout << "2 for subtraction" << endl;
    cout << "3 for multiplication" << endl;
    cout << "4 for division" << endl;
    cout << "5 to quit" << endl;
    cin >> c;
    if (c < 1 || c > 5) {
      while (c < 1 || c > 5) {
        cout << "Error: please enter a valid number: ";
        cin >> c;
      }
     }
    if (c == 5) {
      return 0;
     }
    cout << "You chose: " << c << endl;
    cout << "Enter two numbers: ";
    cin >> x >> y;    
    switch (c) {
      case 1: 
        s = sum(x,y);
        cout << "The sum of " << x << " and " << y << " is " << s << endl;
        break;
      case 2:
        d = difference(x,y);
        cout << "The difference of " << x << " and " << y << " is " << d<<endl;
        break;
      case 3: 
        p = product(x,y);
        cout << "The product of " << x << " and " << y << " is " << p << endl;
        break;
      case 4:
        q = quotient(x,y);
        cout << "The quotient of " << x << " and " << y << " is " << q << endl;
        break;
    }
} while(c != 5);
return 0;
}

float sum(float x, float y) {
   float s;
     s = x + y;
     return s;
}

float difference(float x, float y) {
   float d;
     d = x - y;
     return d;
}

float product(float x, float y) {
   float p;
     p = x*y;
     return p;
}

float quotient(float x, float y) {
   float q;
    q = x/y;
    return q;
}


