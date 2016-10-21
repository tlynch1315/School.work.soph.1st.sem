// Tommy Lynch NDID: Tlynch2
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
  int i, j, count = 0;
  int primes[1000];
  for (i = 2;i < 1000; i++) {
    primes[i] = 1;
  }
				// make array of 1's
  for (i = 2; i < 1000;i++) {
    if (primes[i] == 0) {
      primes[i] = 0;
    }
				// if the value was already made false, keep
				// it as false
    else if (primes[i] == 1) {
     int  n;
      for (n = 2; (i*n) < 1000;++n) {
        primes[i*n] = 0;
      }
    }
				// if the for loop encounters a 1, then that
				// position is a prime number and sets all 
				// multiples of that number as 0, which means 
				// it is not prime
  }
  for (i = 2; i < 1000; i++) {
    if (primes[i] == 1) {
      if (count == 10) {
        cout << endl;
        count = 0;
      }
      cout << setw(5) << i;
      count++;
    }
  }
				// outputs all values of the position of the 
				// array where the value is 1, which means
				// that position is a prime number
				// count counts the outputs and after
				// 10 outputs it starts a new line
cout << endl;

return 0;
}
