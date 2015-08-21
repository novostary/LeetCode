#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	// Runtime: 8 ms
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) {
			return "";
		}
		string pre = strs[0];
		size_t vSize = strs.size();
		for (size_t i = 1; i < vSize; i++) {
			string str = strs[i];
			size_t j = 0;
			size_t preSize = pre.size(), strSize = str.size();
			for (; j < preSize && j < strSize; j++) {
				if (pre[j] != str[j]) {
					break;
				}
			}
			if (j == 0) {
				return "";
			}
			else {
				pre = pre.substr(0, j);
			}
		}
		return pre;
	}

	// Runtime: 4 ms
	//     string longestCommonPrefix(vector<string>& strs) {
	// 		if (strs.empty()) {
	// 			return "";
	// 		}
	// 		size_t len = strs.size();
	// 		vector<size_t> size(len, 0);
	// 		size_t minSize = INT_MAX;
	// 		for (size_t i = 0; i < len; i++) {
	// 			size[i] = strs[i].size();
	// 			minSize = min(minSize, size[i]);
	// 		}

	// 		for (size_t prefix = 0; prefix < minSize; prefix++) {
	// 			char ch = strs[0][prefix];
	// 			for (size_t i = 1; i < len; i++) {
	// 				if (ch != strs[i][prefix]) {
	// 				// 	if (prefix == 0) {
	// 				// 		return "";
	// 				// 	}
	// 				// 	else {
	// 						return strs[0].substr(0, prefix);
	// 				// 	}
	// 				}
	// 			}
	// 		}
	// 		return strs[0].substr(0, minSize);
	// 	}
};