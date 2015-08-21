#include <vector>
using std::vector;
// Runtime: 12 ms
// https://leetcode.com/discuss/6632/challenge-me-thx 
// https://leetcode.com/discuss/31595/detailed-explanation-generalization-bitwise-operation-numbers general
// http://blog.csdn.net/novostary/article/details/47812813 my explanation
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