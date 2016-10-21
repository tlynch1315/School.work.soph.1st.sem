#include<iostream>
using namespace std;

int main() 
{
  int t;
  cout << "please enter the number of touchdowns your team has: ";
  cin >> t;
  
  int e;
  cout << "please enter the number of extra points your team has: ";
  cin >> e;
  
  int f;
  cout << "please enter the number of field goals your team has: ";
  cin >> f;
  
  int s;
  cout << "please enter the number of safeties your team has: ";
  cin >> s;
  int score;
  score = (7*t)+(1*e)+(f*3)+(s*2);
  cout << "Your team's score is:"<< score << endl;
}
