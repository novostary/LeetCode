#include <cmath>
// Runtime: 4 ms
// https://en.wikipedia.org/wiki/Happy_number
class Solution {
public:

	bool isHappy(int n) {
		if (n <= 0) {
			return false;
		}
		int slow = n, fast = squareDigit(n);
		while (slow != fast) {
			slow = squareDigit(slow);
			fast = squareDigit(squareDigit(fast));
		}
		return slow == 1;
	}

	// bool isHappy(int n) {
	//     if (n <= 0) {
	//         return false;
	//     }

	//     unordered_set<int> s;
	//     while (n != 1) {
	//         if (s.find(n) == s.end()) {
	//             s.insert(n);
	//             n = squareDigit(n);
	//         } else {
	//             return false;
	//         }
	//     }
	//     return true;
	// }
	int squareDigit(int n) {
		int ret = 0;
		int tmp;
		while (n != 0) {
			tmp = n % 10;
			ret += tmp * tmp; // pow(double, double)
			n /= 10;
		}
		return ret;
	}
};