
// Runtime: 76 ms
// Best: 68 ms ???
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) {
			return false;
		}
		int reverse = 0;
		while (x > reverse) {
			reverse = reverse * 10 + x % 10;
			x /= 10;
		}
		return (x == reverse) || (x == reverse / 10);
	}

	bool isPalindrome2(int x) {
		// Runtime: 72 ms
		if (x == 0) return true;
		// in leetcode, negative numbers and numbers with ending zeros
		// are not palindrome
		if (x < 0 || x % 10 == 0)
			return false;

		// reverse half of the number
		// the exit condition is y >= x
		// so that overflow is avoided.
		int y = 0;
		while (y < x) {
			y = y * 10 + (x % 10);
			if (x == y)  // to check numbers with odd digits
				return true;
			x /= 10;
		}
		return x == y; // to check numbers with even digits
	}
};