public class Solution {
	// Runtime: 452 ms
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
    
    // Runtime: 572 ms
    public String longestPalindrome2(String s) {
        if (s.isEmpty()) {
			return s;
		}
		String sExtend = "$#";
		for (int i = 0; i < s.length(); i++) {
			sExtend = sExtend + s.charAt(i) + '#';
		}
		sExtend += '`';
		Integer[]p;
		p = new Integer[sExtend.length()];
		for (int i = 0; i < p.length; i++) 
			p[i] = 1;
		int maxMiddleSub;
		
		int mx = 2, id = 1;
		for (int i = 1; i < sExtend.length() - 1; i++) {
			if (i < mx) {
				if (mx - i > p[2 * id - i]) {
					p[i] = p[2 * id - i];
				} else {
					p[i] = mx - i;
				}
			} else {
				p[i] = 1;
			}
			while (sExtend.charAt(i + p[i]) == sExtend.charAt(i - p[i])) {
				p[i]++;
			}
			if (i + p[i] > mx) {
				id = i;
				mx = i + p[i];
			}
		}
		maxMiddleSub = 1;
		for (int i = 2; i < p.length; i++) {
			if (p[maxMiddleSub] < p[i]) {
				maxMiddleSub = i;
			}
		}
		
		
		if (maxMiddleSub % 2 == 0) {
			return s.substring(maxMiddleSub / 2 - 1 - p[maxMiddleSub] / 2 + 1, maxMiddleSub / 2 - 1 + p[maxMiddleSub] / 2);
		} else {
			return s.substring(maxMiddleSub / 2 - 1 - p[maxMiddleSub] / 2 + 1, maxMiddleSub /2 + p[maxMiddleSub] / 2);
		}
    }
}
