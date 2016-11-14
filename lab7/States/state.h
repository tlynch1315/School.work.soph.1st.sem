// Tommy Lynch NDID: tlynch2
// state.h
// interface for state class
#include<string>
using namespace std;

class State {
  public:
    State();
    State(string , string , string , int , int , int );
    ~State();
    void setAbbrev(string);
    void setName(string);
    void setCapital(string);
    void setPopulation(int);
    void setYear(int);
    void setReps(int);
    string getAbbrev();
    string getName();
    string getCapital();
    int getPopulation();
    int getYear();
    int getReps();
    void print();
  private:
    string abbrev;
    string name;
    string capital;
    int pop;
    int year;
    int reps;
};
