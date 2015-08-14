#include <string>
using std::string;
// Runtime: 0 ms

class Solution {
public:
	int titleToNumber(string s) {
		int n = 0;
		for (auto ch : s) {
			n = n * 26 + ch - 'A' + 1;
		}
		return n;
	}
};