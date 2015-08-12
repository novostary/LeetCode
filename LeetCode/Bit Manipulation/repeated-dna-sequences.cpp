#include <vector>
#include <string>
using std::string;
using std::vector;
// Runtime: 8 ms
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ret;
		// int hashmap[1048576] = {0}; // 20 ms
		char hashmap[1048576] = { 0 }; // 8 ms
		// memset(hashmap, 0, sizeof(hashmap));
		for (int i = 0, t = 0; i < s.size(); i++) {
			t = t << 2 & 0xfffff | (s[i] - 64) % 5;
			// t = t << 2 & 0xfffff | (s[i] & 0x1f) % 5; // 12 ms
			if (hashmap[t]++ == 1) {
				ret.push_back(s.substr(i - 9, 10));
				hashmap[t] = 2; // 12 ms
			}
		}
		return ret;
	}

	// vector<string> findRepeatedDnaSequences(string s) {
	//     // Runtime: 24 ms
	//     vector<string> ret;
	//     int hashmap[1048576];
	//     memset(hashmap, 0, sizeof(hashmap));
	//     for (int i = 0, t = 0; i < s.size(); i++) {
	//         t = t << 2 & 0xfffff | (s[i] - 64) % 5;
	//         if (hashmap[t]++ == 1) {
	//             ret.push_back(s.substr(i - 9, 10));
	//         }
	//     }
	//     return ret;
	// }

	// vector<string> findRepeatedDnaSequences(string s) {

	//     vector<string> ret;
	//     unordered_map<int, int> m;
	//     for (int i = 0, t = 0; i < s.size(); i++) {
	//         // t = t << 3 & 0x3fffffff | s[i] & 0x7; // 112 ms
	//         t = t << 2 & 0xfffff | (s[i] - 64) % 5; // 112 ms
	//         if (m.find(t) == m.end()) {
	//             m[t] = 1;
	//         } else if (m[t]) {
	//             m[t] = 0;
	//             ret.push_back(s.substr(i - 9, 10));
	//         }
	//     }
	//     return ret;
	// }

	// vector<string> findRepeatedDnaSequences(string s) {
	//     // 112 ms
	//     vector<string> ret;
	//     unordered_map<int, bool> m;
	//     for (int i = 0, t = 0; i < s.size(); i++) {
	//         t = t << 3 & 0x3fffffff | s[i] & 0x7;
	//         if (m.find(t) == m.end()) {
	//             m[t] = true;
	//         } else if (m[t]) {
	//             m[t] = false;
	//             ret.push_back(s.substr(i - 9, 10));
	//         }
	//     }
	//     return ret;
	// }

	// vector<string> findRepeatedDnaSequences(string s) {
	//     // Memory Limit Exceeded
	//     vector<string> ret;
	//     unordered_map<string, bool> m;
	//     for (int i = 0; i + 10 <= s.size(); i++) {
	//         if (m.find(s.substr(i, i + 10)) == m.end()) {
	//             m[s.substr(i, i + 10)] = true;
	//         } else if (m[s.substr(i, i + 10)]) {
	//             m[s.substr(i, i + 10)] = false;
	//             ret.push_back(s.substr(i, i + 10));
	//         }
	//     }
	//     return ret;
	// }
};