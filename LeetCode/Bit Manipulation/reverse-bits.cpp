#include <cstdint>
// Runtime: 4 ms
// ”≈œ»º∂
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ret = 0;
		for (int i = 0; i < 32; i++) {
			// ret = (ret << 1) + n & 1;
			// ret = (ret << 1) + (n & 1);
			// Input:           1 (00000000000000000000000000000001)
			// Output:           0 (00000000000000000000000000000000)
			// Expected:  2147483648 (10000000000000000000000000000000)
			ret = (ret << 1) | (n & 1);
			n = n >> 1;
		}
		return ret;
	}

	uint32_t reverseBits2(uint32_t n) {
		n = (n >> 16) | (n << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
};