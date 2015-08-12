
// Runtime: 64 ms
// https://leetcode.com/discuss/43070/three-solution-explanation-loops-recursion-extra-variable
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		// return n > m ? rangeBitwiseAnd(m >> 1, n >> 1) << 1 : m; // 68 ms
		int b = 0;
		while (m != n) {
			if (m == 0) { // 64 ms
				return 0;
			}
			++b;
			m >>= 1;
			n >>= 1;
		}
		return m << b;
	}

	int rangeBitwiseAnd2(int m, int n) {
		// 64 ms
		while (n > m) {
			n &= (n - 1);
		}
		return n;
	}
};