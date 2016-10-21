#include<iostream>
#include<iomanip>

using namespace std;

int main() {

  int x;
   cout << "enter the width of the table: ";
   cin >> x;
  int y;
   cout << "enter the height of the table: ";
   cin >> y;
  int i, j;
cout << "*";
for (int top=1;top<=x;top++) {
    cout << setw(5) << top;
}
cout << endl;
for (i=1;i<=y;i++) {
cout << i;     
for (j=1; j<=x; j++) {
 	  cout << setw(5) << i*j;
   	}
   cout << endl;
}
}

