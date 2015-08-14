#include <string>
using std::string;
// Runtime: 36 ms
class Solution {
public:
	int romanToInt(string s) {
		if (s.empty()) {
			return 0;
		}
		int ret = 0;
		int size = s.size();
		for (int i = 0; i < size - 1; i++) {
			if ('I' == s[i] && ('V' == s[i + 1] || 'X' == s[i + 1])
				|| 'X' == s[i] && ('L' == s[i + 1] || 'C' == s[i + 1])
				|| 'C' == s[i] && ('D' == s[i + 1] || 'M' == s[i + 1])) {
				ret -= romanCharToInt(s[i]);
			}
			else {
				ret += romanCharToInt(s[i]);
			}
		}
		ret += romanCharToInt(s[size - 1]);
		return ret;
	}
	int romanCharToInt(char c) {
		switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
	}
};