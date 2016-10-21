// Tommy Lynch NDID: Tlynch2

#include<iostream>
#include<valarray>
using namespace std;

bool isprime(int );
bool ispan(int );

int main() {
  int maxpp, prime, pan;
  int x = 1;
    for (;x<=999999999;x++) {
     prime = isprime(x);
     pan = ispan(x);
     if (prime) {
       if (pan) {
       maxpp = x;
     }
     }
}
cout << "The largest pandigital prime number is: " << maxpp << endl;
return 0;
}

bool isprime(int x) {
  int r, i;
  bool prime;
  for (i = 2;i<=x/2;i++) {
      prime = true;
       r = x%i;
      if (r == 0) {
      prime = false;
        break;
       }
     }
return prime;
}

bool ispan(int x) {
  int j, l, sum;
  bool pan;
  l = 1;
  while (x/=10) {
    l++;
  }
  int array[l];
    for (j = 0; j<l;j++) {
     array[j] = x % 10;
     x/= 10;
    }
    pan = true;
    sum = 0;
    for (j = 0; j<l; j++) {
      sum = sum + array[j];
    }
    if (l == 5) {
      if (sum != 15) {
       pan = false;
      }
    }
    if (l == 6) {
      if (sum != 21) {
       pan = false;
      }
    }
    if (l == 7) {
      if (sum != 28) {
       pan = false;
      }
    }
    if (l == 8) {
      if (sum != 36) {
       pan = false;
      }
    }
    if (l == 9) {
      if (sum != 45) {
       pan = false;
      }
    }
return pan;
}
