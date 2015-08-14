#include <string>
using std::string;
// Runtime: 4 ms
// https://leetcode.com/discuss/40846/c-4ms-solution-inspired-by-hardware-full-adder-circuit
// https://en.wikipedia.org/wiki/Adder_%28electronics%29#Full_adder
class Solution {
public:
	string addBinary(string a, string b) {
		string ret = "";
		int i = a.size() - 1, j = b.size() - 1, c = 0;
		while (i >= 0 || j >= 0 || c == 1) {
			c += i >= 0 ? a[i--] - '0' : 0;
			c += j >= 0 ? b[j--] - '0' : 0;
			// ret = char(c % 2 + '0') + ret; // Runtime: 4 ms
			ret = static_cast<char>(c % 2 + '0') + ret; // Runtime: 4 ms
			c >>= 1;
		}
		return ret;
	}
};