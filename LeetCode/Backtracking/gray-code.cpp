#include <vector>
using std::vector;
// Runtime: 4 ms
// https://leetcode.com/discuss/24634/an-accepted-three-line-solution-in-java
// https://leetcode.com/discuss/1525/what-if-i-have-no-knowledge-over-gray-code-before
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ret(pow(2, n), 0);
		for (int i = 0; i < ret.size(); i++) {
			ret[i] = i ^ i >> 1;
		}
	}
	vector<int> grayCode2(int n) {
		vector<int> ret(1, 0);
		int t = 1;
		for (int i = 0; i < n; i++) {
			for (int j = ret.size() - 1; j >= 0; j--) {
				ret.push_back(ret[j] ^ t);
			}
			t <<= 1;
		}
		return ret;
	}
};