// Tommy Lynch NDID: Tlynch2

#include<iostream>
#include<fstream>
#include<list>
#include<iomanip>
#include<string>
#include<iterator>
#include<cctype>
using namespace std;
void dispfreq(int [], float, float );
int main(){
  int freq[128];
  for (int k = 0;k<128;k++){
    freq[k] = 0;
  }
				// initialize the array of ints to 0
  char str;
  float spaces = 0;
  float total = 0;
  string filename;
  ifstream ifs;
  cout << "Enter file name: ";
  cin >> filename;
  ifs.open(filename);

  if (!ifs){
    cout << "Error opening file " << filename << endl;
    return 1;
  }
  
  str = ifs.get();
  while(!ifs.eof()){
    str = toupper(str);
    freq[str]++;
    if(isspace(str)){
      spaces++;
    }
    total++;
    str = ifs.get();
  }
				// read in file char by char and make uppercase
  dispfreq(freq, spaces, total);
return 0;
}


void dispfreq(int freq[], float spaces, float total){
  int i = 0;
  for(char ch = 'A'; ch <= 'Z'; ch++){
    i++;
    cout << ch << " : " << setw(2) << freq[ch] << " ";
    if (i == 7){
    cout << endl;
    i = 0;
    }
  }
  cout << endl; 
  float letters = total-spaces;
  float percent = (spaces/total)*100;
  cout << "There are " << letters << " letters\n";
  cout << "There are " << total << " total spaces\n";
  cout << "There are " << spaces << " whitespaces\n";
  cout << "Space percentage: " << setprecision(3)  << percent << "%\n";
}
				// function outputs the frequencies
