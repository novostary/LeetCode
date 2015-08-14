// Runtime: 4 ms
class Solution {
public:
	double myPow(double x, int n) {
		if (n < 0) {
			return 1 / (x * myPow(x, -(n + 1)));
		}
		else if (n == 0) {
			return 1;
		}
		else if (n == 1) {
			return x;
		}
		else {
			double tmp = myPow(x, n >> 1);
			if (n % 2 == 1) {
				return tmp * tmp * x;
			}
			else {
				return tmp * tmp;
			}
		}
	}
};