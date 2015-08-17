#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;
// Runtime: 64 ms
// Best: 40 ms
class Solution {
public:
	// vector<vector<string>> groupAnagrams(vector<string>& strs) {
	//     unordered_map<string, int> index;
	//     vector<vector<string>> ret;
	//     int i = 0;
	//     for (auto str : strs) {
	//         string ascendingStr(str);
	//         sort((char*)ascendingStr.c_str(), (char*)ascendingStr.c_str() + ascendingStr.size());
	//         if (index.find(ascendingStr) != index.end()) {
	//             ret[index[ascendingStr]].push_back(str);
	//         } else {
	//             index[ascendingStr] = i;
	//             i++;
	//             vector<string> v(1, str);
	//             ret.push_back(v);
	//         }
	//     }
	//     for (auto& v : ret) {
	//         sort(v.begin(), v.end());
	//     }
	//     return ret;
	// }

	string sortLowercase(string s) {
		int charExist[26] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			charExist[s[i] - 'a']++;
		}
		string res;
		int j = 0;
		while (j < 26) {
			if (charExist[j] == 0) {
				j++;
			}
			else {
				res.push_back(j + 'a');
				charExist[j]--;
			}
			// if (charExist[j] != 0) {
			//     res += string(charExist[j], j + 'a');
			// }
			// j++;
		}
		return res;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, int> index;
		vector<vector<string>> ret;
		int i = 0;
		for (auto str : strs) {
			// string ascendingStr = ascendingAnagram(str);
			string ascendingStr = sortLowercase(str); // Runtime: 68 ms
			if (index.find(ascendingStr) != index.end()) {
				ret[index[ascendingStr]].push_back(str);
			}
			else {
				// index[ascendingStr] = i;
				// i++;
				index[ascendingStr] = i++;
				// vector<string> v(1, str);
				// ret.push_back(v);
				ret.push_back(vector<string>(1, str)); // 64 ms
			}
		}
		for (auto& v : ret) {
			if (v.size() > 1)
				sort(v.begin(), v.end());
		}
		return ret;
	}

	// 80 ms
	/*vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> mp;
		for (string s : strs) {
			string t = sortLowercase(s);
			mp[t].insert(s);
		}
		vector<vector<string>> anagrams;
		for (auto m : mp) {
			vector<string> anagram(m.second.begin(), m.second.end());
			anagrams.push_back(anagram);
		}
		return anagrams;
	}*/

	// string ascendingAnagram(string s) {
	//     sort((char*)s.c_str(), (char*)s.c_str() + s.size());
	//     return s;
	// }
};