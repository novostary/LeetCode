#include <string>
using std::string;
using std::to_string;

class Solution {
public:
	string countAndSay(int n) { // Runtime: 4 ms
		if (n == 1) {
			return "1";
		}
		string res = "1";
		string s;
		int len;
		for (int i = 1; i < n; ++i) {
			len = res.size();
			s = "";
			for (int j = 0; j < len; ++j) {
				int count = 1;
				while (j + 1 < len && res[j] == res[j + 1]) {
					++count;
					++j;
				}
				s += to_string(count) + res[j];
			}
			res = s;
		}
		return res;
	}
};