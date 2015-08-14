// Runtime: 4 ms
class Solution {
public:
	// int trailingZeroes(int n) {
	//     return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
	// }

	int trailingZeroes(int n) {
		int count = 0;
		while (n >= 5) {
			count += n / 5;
			n /= 5;
		}
		return count;
	}
};