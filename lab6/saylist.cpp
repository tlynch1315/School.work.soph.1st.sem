// Tommy Lynch NDID: Tlynch2
#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<iomanip>
#include<iterator>

using namespace std;
void dispsayings(list<string> &sayings );
void newsaying(list<string> &sayings);
void sayword(list<string> &sayings);
void newfile(list<string> &sayings);
void deletesaying(list<string> &sayings);
void sortsayings(list<string> &sayings);
int main() {
  list<string>sayings;
  string str;
  string filename;
  cout << "Enter data file name: ";
  cin >> filename;
  fstream fp(filename);
  getline(fp,str);
				// initialize list, get file name and first line
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
				// makes a list of strings containing all of the
				// sayings from the file
sortsayings(sayings);
				// sorts sayings initially
int choice = 1;
  while(choice != 6) {
    cout << "Please choose one of the following: \n";
    cout << "1 to display all sayings currently in the database\n";
    cout << "2 to enter a new saying into the database\n";
    cout << "3 to list sayings that contain a given word\n";
    cout << "4 to save all sayings in a new text file\n";
    cout << "5 to delete a saying\n";
    cout << "6 to quit the program\n";
    cin >> choice;
    cout << endl;
    switch (choice) {
      case 1:
        dispsayings(sayings);
        break;
      case 2:
	newsaying(sayings);
	sortsayings(sayings);
	break;
      case 3:
	sayword(sayings);
	break;
      case 4:
	newfile(sayings);
	break;
      case 5:
	dispsayings(sayings);
	deletesaying(sayings);
	break;
      case 6:
	return 0;
      default:
	cout << "Please enter a valid value.";
	break;
    }
				// switch case for choices the user can choose
  cout << endl;  
  }
}

void dispsayings(list<string> &sayings ){
  int count = 1;
  for(auto it = sayings.begin(); it != sayings.end(); ++it) {
    cout << setw(2) << count++ << " " << *it << endl;
  }
}
				// function displays the entire list of 
				// strings
void newsaying(list<string> &sayings){
  string phrase;
  cout << "Enter a new phrase: ";
  cin.ignore();
  getline(cin, phrase);
  sayings.push_back(phrase);

}
				// function enters a new saying
void sayword(list<string> &sayings){
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
void newfile(list<string> &sayings){
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
void deletesaying(list<string> &sayings){
  int num;
  cout << "Enter the number of the saying you would like to delete: ";
  cin >> num;
  num-=1;
  for (auto it = sayings.begin(); it != sayings.end(); it++){
    int index = std::distance(sayings.begin(), it);
    if (num == index) {
      sayings.erase(it);
      break;
    }
  }
}
				// function deletes a specific saying

void sortsayings(list<string> &sayings){
  bool swp = true;
  while(swp == (true)){
    swp = false;
    list<string>::iterator itprev = sayings.begin();
    list<string>::iterator it = sayings.begin();
    it++;
    while(it != sayings.end()){
      if ((*itprev).compare((*it)) > 0){
        string temp = (*it);
        (*it) = (*itprev);
        (*itprev) = temp;
	swp = true;
      }
      itprev++;
      it++; 
    }
  }
}
				// function sorts sayings in alphabetical order
				//two different iterators one apart that run
				//through the list
