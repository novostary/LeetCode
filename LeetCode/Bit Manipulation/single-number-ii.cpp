#include <vector>
using std::vector;
// Runtime: 12 ms
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0, reset = 0;
		for (auto num : nums) {
			twos = twos | (ones & num);
			ones = ones ^ num;
			reset = ones & twos;
			ones = ones ^ reset;
			twos = twos ^ reset;
		}
		return ones;
	}

	int singleNumber2(vector<int>& nums) {
		int ones = 0, twos = 0;
		for (auto num : nums) {
			ones = (ones ^ num) & ~twos;
			twos = (twos ^ num) & ~ones;
		}
		return ones;
	}
};