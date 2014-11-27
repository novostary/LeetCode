public class Solution {
	// https://oj.leetcode.com/problems/permutation-sequence/
	// 388 ms
	public String getPermutation(int n, int k) {
		// k <= n! && k > 0
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++) {
            list.add(i);
        }
        String s = "";
        int nn = 1;
        for (int i = 1; i <= n; i++) {
        	nn *= i;
        }
        k -= 1;
        for (int i = n; i > 0 && k > 0; i--) {
        	nn /= i;
            s += list.get(k / nn);
            list.remove(k / nn);
            k %= nn;
        }
        for (int i = 0; i < list.size(); i++) {
        	s += list.get(i);
        }
		return s;
    }
}
