#include <cstdlib>

// Runtime: 8 ms
// https://leetcode.com/discuss/38997/detailed-explained-8ms-c-solution
// 如何避免使用long long
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}
		bool positive = (dividend < 0) ^ (divisor < 0) ? false : true;
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		int res = 0;
		while (dvd >= dvs) {
			long long tmp = dvs;
			long long multiple = 1;
			while (dvd > tmp << 1) {
				tmp <<= 1;
				multiple <<= 1;
			}
			dvd -= tmp;
			res += multiple;
		}
		return positive ? res : -res;
	}
};