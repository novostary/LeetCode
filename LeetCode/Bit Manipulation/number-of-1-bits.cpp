#include <cstdint>
// Runtime: 4 ms
// https://leetcode.com/discuss/27609/short-code-by-time-the-count-and-another-several-method-time
// https://en.wikipedia.org/wiki/Hamming_weight#Efficient_implementation
class Solution {
public:
	int hammingWeight(uint32_t n) {
		n -= n >> 1 & 0x55555555;
		n = (n & 0x33333333) + (n >> 2 & 0x33333333);
		n = (n + (n >> 4)) & 0x0f0f0f0f;
		n += n >> 8;
		n += n >> 16;
		return n & 0x3f;
	}

	// int hammingWeight(uint32_t n) { // 8 ms
	//     n -= n >> 1 & 0x55555555;
	//     n = (n & 0x33333333) + (n >> 2 & 0x33333333);
	//     n = (n + (n >> 4)) & 0x0f0f0f0f;
	//     return (n * 0x01010101) >> 24;
	// }

	// int hammingWeight(uint32_t n) {
	//     n = (n & 0x55555555) + (n >> 1 & 0x55555555); // 2
	//     n = (n & 0x33333333) + (n >> 2 & 0x33333333); // 4
	//     n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f); // 8
	//     n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff); // 16
	//     n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff); // 32
	//     return n;
	// }

	// int hammingWeight(uint32_t n) {
	//     int count = 0;
	//     while (n != 0) {
	//         n &= (n - 1);
	//         count++;
	//     }
	//     return count;
	// }
};