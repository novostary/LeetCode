#include <string>
#include <algorithm>
using std::string;
using std::sort;
// https://leetcode.com/discuss/49374/2-c-solutions-with-explanations 有一些编译优化方面的内容
class Solution {
public:
	// Runtime: 12 ms
	bool isAnagram(string s, string t) {
		// unordered_map
		int num[26] = { 0 };
		for (auto ch : s) {
			num[ch - 'a']++;
		}
		for (auto ch : t) {
			num[ch - 'a']--;
		}
		for (auto n : num) {
			if (n) {
				return false;
			}
		}
		return true;
	}

	// Runtime: 76 ms
	bool isAnagram2(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}

	// Runtime: 48 ms
	bool isAnagram3(string s, string t) {
		std::sort((char*)s.c_str(), (char*)s.c_str() + s.size());
		std::sort((char*)t.c_str(), (char*)t.c_str() + t.size());
		return s == t;
	}
};