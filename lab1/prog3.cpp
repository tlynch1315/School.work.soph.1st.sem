#include<iostream>

using namespace std;

int main()
{
  float m;
  cout << "Enter the mass of the object in kg: ";
  cin >> m;
  
  if ( m <= 0 ) {
    cout << "Error: The mass cannot be negative.";
    return 0;
    }
  float h;
  cout << "Enter the starting height of the object in meters: ";
  cin >> h;
  
  if ( h < 0 ) {
  cout << "Error: The height cannot be negative";
  return 0;
  }
  float pe;
  pe = m*h*9.81;
  cout << "The potential energy of the object is: " << pe << " joules" << endl;
  
}
