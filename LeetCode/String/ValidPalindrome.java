public class Solution {
    public boolean isPalindrome(String s) {
        if (s == null) {
			return false;
		} else if ("".equals(s)) {
			return true;
		}
		s = s.toLowerCase();
		int i = 0, j = s.length() - 1;
		while (true) {
			while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
				i++;
			}
			while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
				j--;
			}
			if (i < j) {
				if (s.charAt(i) == s.charAt(j)) {
					i++;
					j--;
				} else {
					return false;
				}
			} else {
				return true;
			}
		}
    }
}
