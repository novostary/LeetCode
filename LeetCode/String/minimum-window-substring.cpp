#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
// I haven't understood the answer of LeetCode. Maybe my answer is more clear.
class Solution {
public:
	string minWindow(string s, string t) { // Runtime: 12 ms
		// unordered_map<char, int> mapT;
		int mapT[256] = { 0 }; // char maybe overflow!
		int countT = t.size();
		for (auto ch : t) {
			mapT[ch]++;
		}

		int left = 0, right = 0;
		int countS = 0;
		// unordered_map<char, int> mapS;
		int mapS[256] = { 0 };
		string res = "";
		while (right < s.size()) {
			char ch = s.at(right);
			if (mapT[ch] != 0) {
				mapS[ch]++;
				if (mapS[ch] <= mapT[ch]) {
					countS++;
				}
			}
			if (countS == countT) {
				while (true) {
					ch = s.at(left);
					if (mapT[ch] != 0) {
						if (mapS[ch] > mapT[ch]) {
							mapS[ch]--;
						}
						else {
							break;
						}
					}
					left++;
				}
				if (res.empty() || res.size() > right - left + 1) {
					res = s.substr(left, right - left + 1);
				}
				mapS[s.at(left)]--;
				countS--;
				left++;

			}
			right++;
		}
		return res;
	}

	 string minWindow2(string s, string t) { // Runtime: 128 ms
	     unordered_map<char, int> mapT;
	     int countT = t.size();
	     for (auto ch : t) {
	         mapT[ch]++;
	     }

	     int left = 0, right = 0;
	     int countS = 0;
	     unordered_map<char, int> mapS;
	     string res = "";
	     while (right < s.size()) {
	         char ch = s.at(right);
	         if (mapT.find(ch) != mapT.end()) {
	             mapS[ch]++;
	             if (mapS[ch] <= mapT[ch]) {
	                 countS++;
	             }
	         }
	         if (countS == countT) {
	             while (true) {
	                 ch = s.at(left);
	                 if (mapT.find(ch) != mapT.end()) {
	                     if (mapS[ch] > mapT[ch]) {
	                         mapS[ch]--;
	                     } else {
	                         break;
	                     }
	                 }
	                 left++;
	             }
	             if (res.empty() || res.size() > right - left + 1) {
	                 res = s.substr(left, right - left + 1);
	             }
	             mapS[s.at(left)]--;
	             countS--;
	             left++;

	         }
	         right++;
	     }
	     return res;
	 }
};