// Tommy Lynch NDID: TLynch2

#include<unordered_map>
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
    /*void sortString(string&s) {
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
    */
    bool isAnagram(string s, string t) {
      unordered_map<char, int> array1;
      unordered_map<char, int> array2;
      for (int i = 0; i < s.size(); i++) array1[s[i]]++;
      for (int j = 0; j < t.size(); j++) array2[t[j]]++;
      return array1 == array2;
    }
				// insertion sort was too long also, so I decided to 
				// use unordered_maps with char as a reference 
				// and int as content. I went through each 
				// string and added one to each point 
				// referenced by the individual chars
				// in the strings then compared the two maps
				// this was accepted by leetcode.com
};
