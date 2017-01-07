// Tommy Lynch NDID: Tlynch2

#include<algorithm>
#include<unordered_map>
#include<set>
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, multiset<string>> mapAnagram;
      for (string i : strs) {
				// automatically iterates over the vector strs
        string word = i;
        sort(word.begin(), word.end());
	mapAnagram[word].insert(i);
      }
				// this for loop takes each string in strs and sets it 
				// equal to a temp string "word" and then sorts word 
				// and used word as a key to reference the 
				// unordered_map and adds the original unsorted
				// string to the map with that reference
      vector<vector<string>> groupedAnagrams;
      for (auto map : mapAnagram) {
				// automatically iterates through the unordered_map
				// called mapAnagram using map as an iterator
        vector<string> anagram(map.second.begin(), map.second.end());
				// map.second refers to the second element in the 
				// pair of values for that point in the 
				// unordered_map, which in this case is a pair of
				// <string, multiset<string> so the second
				// element is a multiset of strings and then it
				// initializes a vector called anagram that goes from
				// the beginning of that multiset to the end,
				// which is actually a group of anagrams
	groupedAnagrams.push_back(anagram);
				// pushes the vector<vector<string>> back the vector of
				// anagrams intialized above
      }
    return groupedAnagrams;
  }
};
