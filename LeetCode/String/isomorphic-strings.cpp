#include <string>
using std::string;
class Solution {
public:
	// Runtime: 8 ms
	bool isIsomorphic(string s, string t) {
		char map_s[256] = { 0 };
		char map_t[256] = { 0 };
		int slen = s.size();
		for (int i = 0; i < slen; i++) {
			if (map_s[s[i]] != map_t[t[i]]) {
				return false;
			}
			map_s[s[i]] = i + 1;
			map_t[t[i]] = i + 1;
		}
		return true;
	}

	// Runtime: 24 ms
	// bool isIsomorphic(string s, string t) {
	//     if (s.empty()) {
	//         return true;
	//     }
	//     unordered_map<char, char> ht;
	//     unordered_set<char> used;
	//     int slen = s.size();
	//     for (int i = 0; i < slen; i++) {
	//         if (ht.find(s[i]) != ht.end()) {
	//             if (ht[s[i]] != t[i]) {
	//                 return false;
	//             }
	//         } else {
	//             if (used.find(t[i]) != used.end()) {
	//                 return false;
	//             }
	//             used.insert(t[i]);
	//             ht[s[i]] = t[i];
	//         }
	//     }
	//     return true;
	// }
};