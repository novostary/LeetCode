// Runtime: 8 ms
class Solution {
public:
	bool isUgly(int num) {
		if (num < 1) {
			return false;
		}
		while (num % 2 == 0) {
			num >>= 1;
		}
		while (num % 3 == 0) {
			num /= 3;
		}
		while (num % 5 == 0) {
			num /= 5;
		}

		// if (num > 0)
		//     for (int i=2; i<6; i++)
		//         while (num % i == 0)
		//             num /= i;

		// if (num != 1) {
		//     return false;
		// } else {
		//     return true;
		// }
		return num == 1;
	}
};