
// https://en.wikipedia.org/wiki/Digital_root
class Solution {
public:
	// Runtime: 8 ms
	int addDigits(int num) {
		return 1 + (num - 1) % 9;
	}

	// Runtime: 8 ms
	int addDigits1(int num) {
		// return num == 0 ? 0 : (num % 9 ? num % 9 : 9);
		if (num == 0) {
			return 0;
		}
		else {
			num %= 9;
			if (num == 0) {
				return 9;
			}
			else {
				return num;
			}
		}
	}

	// Runtime: 8 ms
	int addDigits2(int num) {
		if (num < 10) {
			return num;
		}
		else {
			int tmp = 0;
			while (num >= 10) {
				tmp += num % 10;
				num /= 10;
			}
			return addDigits(tmp + num);
		}
	}
};