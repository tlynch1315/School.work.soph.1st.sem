// Tommy Lynch NDID: TLynch2


#include<string>
using namespace std;
class Solution {
public:
   /*void sortString(string &s){
      bool sorted = true;
      char temp;
      while (sorted){
	sorted = false;
	for (int i = 0; i < s.size(); i++){
          if (s[i]>s[i+1]){
	    temp = s[i+1];
	    s[i+1] = s[i];
 	    s[i] = temp;
	    sorted = true;
	  }
	}
      }
    }*/
				// This was bubble sort, but leetcode said that the 
				// time limit was exceeded so I used insertion sort
				// but leetcode still said that the time limit
				// was exceeded
    void sortString(string&s) {
        for(int i = 0; i < s.size(); i++){
            int indMin = i;
            for (int j = i; j < s.size(); j++){
                if (s[indMin]>s[j]){
                    indMin = j;
                }
            }
            char temp = s[i];
            s[i] = s[indMin];
            s[indMin] = temp;
        }
    }
				// insertion sort to sort string
    bool isAnagram(string s, string t) {
      if (s.size() > 1 || t.size() > 1){
        sortString(s);
        sortString(t);
      }
      if (s.compare(t) == 0){
          return true;
      }
      else{
          return false;
      }
    }
};
