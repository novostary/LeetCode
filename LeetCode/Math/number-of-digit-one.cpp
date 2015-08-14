// Runtime: 0 ms
// long long
class Solution {
public:
	int countDigitOne(int n) {
		int ones = 0;
		for (long long m = 1; m <= n; m *= 10) {
			int a = n / m, b = n % m;
			ones += (a + 8) / 10 * m + (a % 10 == 1 ? b + 1 : 0);
			//ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);

			// if (a % 10 == 1) {
			//     ones += a / 10 * m + b + 1;
			// } else if (a % 10 == 0) {
			//     ones += (a / 10) * m;
			// } else {
			//     ones += (a / 10 + 1) * m;
			// }
		}
		return ones;
	}
};