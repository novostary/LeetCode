#include <algorithm>
using std::min;
// Runtime: 8 ms
// https://leetcode.com/discuss/24965/newtons-iterative-method-in-c
// https://leetcode.com/discuss/8897/share-my-o-log-n-solution-using-bit-manipulation
// http://baike.baidu.com/link?url=5Iufed9W38xM__1mD_zxEWYLautwhxD1vReYB1-p76lXbIQCQWmaEP3uOeA1PNTLKLEvJuO-V2aMuUByTN8L2_
// 二分需要考虑如何防止溢出；从二进制的角度来考虑；牛顿
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 0) {
			return 0;
		}
		// signed, 2 ^ 31 - 1
		int l = 1, h = min(46340, x);
		int ans;
		while (l <= h) {
			int mid = l + ((h - l) >> 1);
			int tmp = mid * mid;

			if (tmp == x) {
				return mid;
			}
			else if (tmp < x) {
				l = mid + 1;
				ans = mid;
			}
			else {
				h = mid - 1;
			}

			// if (tmp <= x) {
			// // if (mid <= x / mid) {
			//     l = mid + 1;
			//     ans = mid;
			// } else {
			//     h = mid - 1;
			// }
		}
		return ans;
	}

	int mySqrt2(int x) {
		long ans = 0;
		long bit = 1l << 16;
		while (bit > 0) {
			ans |= bit;
			if (ans * ans > x) {
				ans ^= bit;
			}
			bit >>= 1;
		}
		return (int)ans;
	}

	int mySqrt3(int x) {
		double ans = x;
		double delta = 0.0001;
		while (fabs(ans * ans - x) > delta) {
			ans = (ans + x / ans) / 2;
		}
		return (int)ans;
	}
};