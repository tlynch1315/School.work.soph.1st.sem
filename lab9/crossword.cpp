// Tommy Lynch NDID: Tlynch2
// Crossword anagram
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct crossword {
  char board[15][15];
  char results[15][15];
  vector<string> answers;
  vector<string> anagrams;
  };
struct compare_length {
  bool operator()(const string &l, const string &r) {
    return l.size()>r.size();
  }
};

void initialize(crossword &);
void input(crossword &);
void insert(crossword &);
void outputboard(crossword &);
void outputresults(crossword &);
void outputanswers(crossword &);
int main(){
  crossword puzzle;
  initialize(puzzle);

                                      // outputting the initial board
  input(puzzle);
  insert(puzzle);
  

  outputresults(puzzle);
  outputboard(puzzle);
  outputanswers(puzzle);
}
// **********  FUNCTIONS  **********


void initialize(crossword &cross){
  for (int i = 0; i < 15; i++){
    for (int j = 0; j < 15; j++) {
      cross.board[i][j] = '#';
      cross.results[i][j] = '.';
    }
  }
}
                                    // initializes the board and the answer board
                         
void outputboard(crossword &cross){
 for (int i = 0; i <15; i++){
    for (int j = 0; j < 15; j++){
      cout << cross.board[i][j];
    }
    cout << endl;
  }
}
                                    // outputs the board

void outputresults(crossword &cross){
 for (int i = 0; i <15; i++){
    for (int j = 0; j < 15; j++){
      cout << cross.results[i][j];
    }
    cout << endl;
  }
}
                                    // outputs the answer board
void input(crossword &cross){
  cout << "Enter up to 20 words, max 15 characters each(enter a period when done): ";
  string word, unsorted;
  cin >> word;
  int count = 0;
  while(word != "." && count < 20){
   while (word.size() > 15){
      cout << "word too long, enter shorter word please: ";
      cin >> word;
    }
  unsorted = word;
  cross.answers.push_back(unsorted);
  sort(cross.answers.begin(), cross.answers.end(), compare_length());
  sort(word.begin(), word.end());
  random_shuffle(word.begin(), word.end());
  cross.anagrams.push_back(word);
  sort(cross.anagrams.begin(), cross.anagrams.end(), compare_length());

  count+=1;
  cin >> word;
  }
}
                                    // inputs the words and chages the arrays/vector
                                    // accordingly
void insert(crossword &cross){
  for (int i = 0; i < cross.answers[0].size(); i++){
      cross.board[7][1+i] = ' ';
      cross.results[7][1+i] = (cross.answers[0])[i];
  }

  for (int n = 1; n < cross.answers.size(); n++){
    int row = rand() % 15;
    int col = rand() % 15;
    for (int i = 0; i < cross.answers[n].size(); i++){
      cross.board[row][col + i] = ' ';
    }
    for (int i = 0; i < cross.answers[n].size(); i++){
     cross.results[row][col + i] = (cross.answers[n])[i];
    }
  }
}
                                    // inputs the spaces into the board and the
                                    // answers into the results array
void outputanswers(crossword &cross){
  for (int n = 0; n < cross.answers.size(); n++){
    cout << cross.anagrams[n] << endl;
  }
}
                                    // outputs the vector of anagrams 
