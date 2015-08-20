// Runtime: 0 ms
class Solution {
public:
	int climbStairs(int n) {
		if (n < 1) {
			return 0;
		}
		// int ret[n + 1];
		int *ret = new int[n + 1];
		ret[1] = 1;
		ret[2] = 2;
		for (int i = 3; i <= n; i++) {
			ret[i] = ret[i - 1] + ret[i - 2];
		}
		return ret[n];
	}
};