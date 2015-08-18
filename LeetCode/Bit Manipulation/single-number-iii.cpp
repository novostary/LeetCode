#include <vector>
using std::vector;
// Runtime: 20 ms
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int all = 0;
		for (auto n : nums) {
			all ^= n;
		}
		int bit1 = 1;
		while ((all & 1) == 0) {
			all >>= 1;
			bit1 <<= 1;
		}
		vector<int> ret;
		int a = 0, b = 0;
		for (auto n : nums) {
			if (n & bit1) {
				a ^= n;
			}
			else {
				b ^= n;
			}
		}
		ret.push_back(a);
		ret.push_back(b);
		return ret;
	}
};