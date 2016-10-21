// Tommy Lynch NDID: Tlynch2

#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

int main() {
  int i, j = 0, num = 0;
  float avg, sum = 0;
  int array[50];   // initialize array for grades

  cin >> i;
  array[0] = i;
  while (i >= 0) {
    array[j] = i;
    j++;
    num++;
    cin >> i;
  }                // while loop assigns values to positions in array in order
                   // until the input is a negative number
                   // num++ counts the inputs so it can take the average later
  for (int count = 0; count < num; count++){ 
    sum += array[count];
  }
 		   // for loop sums array 
  avg = sum/num;   
		   // finds average
cout << "The average is: " << avg << endl;
  
  float stdsum = 0;
  for (int count = 0; count < num; count++){
    stdsum +=pow((array[count]-avg),2);
  }
		   // sum squared differences

  float stddeviation;
  stddeviation = sqrt(stdsum/num);
 
cout << "The standard deviaiton is: " << stddeviation << endl;

  

return 0;
}
