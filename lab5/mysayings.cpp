// Tommy Lynch NDID: Tlynch2
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;
void dispsayings(vector<string> &sayings );
void newsaying(vector<string> &sayings);
void sayword(vector<string> &sayings);
void newfile(vector<string> &sayings);
int main() {
  vector<string>sayings;
  string str;
  string filename;
  cout << "Enter data file name: ";
  cin >> filename;
  fstream fp(filename);
  getline(fp,str);
				// initialize vector, get file name and first line
				// of file
  if(!fp){
    cout << "error opening file " << filename << endl;
    return 1;
  }
				// tests if the file opened
  while (!fp.eof()) {
    sayings.push_back(str);
    getline(fp,str);
  }
				// makes a vector of strings containing all of the
				// sayings from the file
int choice = 1;
  while(choice != 5) {
    cout << "Please choose one of the following: \n";
    cout << "1 to display all sayings currently in the database\n";
    cout << "2 to enter a new saying into the database\n";
    cout << "3 to list sayings that contain a given word\n";
    cout << "4 to save all sayings in a new text file\n";
    cout << "5 to quit the program\n";
    cin >> choice;
    cout << endl;
    switch (choice) {
      case 1:
        dispsayings(sayings);
        break;
      case 2:
	newsaying(sayings);
	break;
      case 3:
	sayword(sayings);
	break;
      case 4:
	newfile(sayings);
	break;
      case 5:
	return 0;
      default:
	cout << "Please enter a valid value.";
	break;
    }
				// switch case for choices the user can choose
  cout << endl;  
  }
}

void dispsayings(vector<string> &sayings ){
  for(auto it = sayings.begin(); it != sayings.end(); ++it) {
    cout << *it << endl;
  }
}
				// function displays the entire vector of 
				// strings
void newsaying(vector<string> &sayings){
  string phrase;
  cout << "Enter a new phrase: ";
  cin.ignore();
  getline(cin, phrase);
  sayings.push_back(phrase);

}
				// function enters a new saying
void sayword(vector<string> &sayings){
  string phrase;
  cout << "Enter word: ";
  cin.ignore();
  getline(cin,phrase);
  for(auto it = sayings.begin();it != sayings.end(); ++it) {
    if((*it).find(phrase)!=string::npos) {
      cout << *it << endl;
    }
  }

}
				// function displays sayings containing a 
				// certain word/phrase
void newfile(vector<string> &sayings){
  string file;
  cout << "Enter a new file name: ";
  cin >> file;
  ofstream ofs(file);
  for (auto it = sayings.begin(); it != sayings.end(); ++it) {
    ofs << *it << endl;
  }
}
				// function copies the current file into a new
				// text file
