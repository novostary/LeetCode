#include <string>
using std::string;
// Runtime: 8 ms
// Best: 4 ms
// https://leetcode.com/discuss/38998/explained-4ms-easy-c-solution KMP
class Solution {
public:
	int strStr(string haystack, string needle) {
		int size1 = haystack.size(), size2 = needle.size();
		for (int i = 0; i < size1 - size2 + 1; i++) {
			int j = 0;
			for (; j < size2; j++) {
				if (haystack.at(i + j) != needle.at(j)) {
					break;
				}
			}
			if (j == size2) {
				return i;
			}
		}
		return -1;
	}
};