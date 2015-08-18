#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::to_string;
// Runtime: 8 ms
// Best: 4 ms
// https://leetcode.com/discuss/42595/share-my-4-ms-c-solution
// 对于全零的判断，要么全零，要么必无零，所以，只需要判断第一位即可
// 如果对字符串排序，需要更多的空间来存储数字对应的字符串，如果直接操作数字，则数字转字符串会重复使用
class Solution {
public:
	static bool compareString(const string s1, const string s2) {
		return s1 + s2 > s2 + s1;
	}
	string largestNumber(vector<int>& nums) {
		if (nums.empty()) {
			return "0";
		}
		int lens = nums.size();
		// vector<string> strs(nums.size(), "");
		// for (int i = 0; i < nums.size(); i++) {
		//     strs[i] = to_string(nums[i]);
		// }
		vector<string> strs;
		for (int i = 0; i < lens; i++) {
			strs.push_back(to_string(nums[i]));
		}
		sort(strs.begin(), strs.end(), compareString);
		string s = "";
		for (auto str : strs) {
			s += str;
		}
		if (s[0] == '0') {
			return "0";
		}
		else {
			return s;
		}
		// int pos = 0;
		// while (s[pos] == '0' && pos < s.size() - 1) {
		//     pos++;
		// }
		// s.erase(0, pos);
		// return s;
	}

	// invalid use of non-static member function
	//     static bool compareDigit(const int a, const int b) {
	//         string s1 = to_string(a), s2 = to_string(b);
	//         return s1 + s2 > s2 + s1;
	// //         string s = s2 + s1;
	// // 		if (s.compare(s1 + s2) < 0) {
	// // 			return true;
	// // 		}
	// // 		else {
	// // 			return false;
	// // 		}
	//     }
	//     string largestNumber(vector<int>& nums) {
	//         sort(nums.begin(), nums.end(), compareDigit);

	//         string s = "";
	//         for (auto n : nums) {
	//             s += to_string(n);
	//         }
	//         int zero = 0;
	//         for (; zero < s.size(); zero++) {
	//             if (s[zero] != '0') {
	//                 break;
	//             }
	//         }
	//         if (zero == s.size()) {
	//             return "0";
	//         } else {
	//             return s.substr(zero);
	//         }

	//     }
};