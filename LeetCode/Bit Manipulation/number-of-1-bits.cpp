#include <cstdint>
// Runtime: 4 ms
// https://leetcode.com/discuss/27609/short-code-by-time-the-count-and-another-several-method-time
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n != 0) {
			n &= (n - 1);
			count++;
		}
		return count;
	}
};