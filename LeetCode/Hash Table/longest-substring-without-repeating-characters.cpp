#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::max;
// 16 ms
// Best: 12 ms
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size = s.size();
		if (size < 2) {
			return size;
		}
		vector<int> v(256, -1);
		int maxLen = 0;
		int begin = 0;
		for (int i = 0; i < size; i++) {
			begin = max(begin, v[s[i]] + 1);
			maxLen = max(maxLen, i - begin + 1);
			v[s[i]] = i;
		}
		return maxLen;
	}
	// int lengthOfLongestSubstring(string s) {
	//     int size = s.size();
	//     if (size < 2) {
	//         return size;
	//     }
	//     unordered_map<char, int> m;
	//     m[s[0]] = 0;
	//     int d = 1;
	//     int maxLen = 1;
	//     for (int i = 1; i < size; i++) {
	//         // if (m.count(s[i]) == 0 || m[s[i]] < i - d) {
	//         if (m.find(s[i]) == m.end() || m[s[i]] < i - d) {
	//             d++;
	//         } else {
	//             d = i - m[s[i]];
	//         }
	//         m[s[i]] = i;
	//         maxLen = max(maxLen, d);
	//     }
	//     return maxLen;
	// }
};