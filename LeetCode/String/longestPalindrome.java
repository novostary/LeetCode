public class Solution {
    public String longestPalindrome(String s) {
        int start = 0, end = 0, maxLength = 1;
		int count;
		if (s.isEmpty()) {
			return s;
		}
		for (int i = 0; i < s.length(); i++) {
			count = 1;
			while ((i - count >= 0) && (i + count < s.length()) && (s.charAt(i - count) == s.charAt(i + count))) {
				count++;
			}
			if (2 * (count - 1) + 1 > maxLength) {
				maxLength = 2 * count - 1;
				start = i - count + 1;
				end = i + count - 1;
			}
			count = 0;
			while ((i - count >= 0) && (i + count + 1 < s.length()) && (s.charAt(i - count) == s.charAt(i + count + 1))) {
				count++;
			}
			if ( 2 * count > maxLength) {
				maxLength = 2 * count;
				start = i - count + 1;
				end = i + count;
			}
		}
		
		return s.substring(start, end + 1);
    }
}
