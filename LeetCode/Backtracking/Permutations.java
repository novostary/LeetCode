public class Solution {
	// https://oj.leetcode.com/problems/permutations/
	// 440 ms
	public List<List<Integer>> permute(int[] num) {
		List<List<Integer>> lists = new ArrayList<List<Integer>>();
		calcPermute(lists, num, 0, num.length - 1);
		return lists;
	}
	public void calcPermute(List<List<Integer>> lists, int[] num, int from, int to) {
		if(from == to) {
			List<Integer> l = new ArrayList<Integer>();
			for (int i = 0; i < num.length; i++) {
				l.add(num[i]);
			}
			lists.add(l);
		} else {
			for (int i = from; i <= to; i++) {
				swap(num, from, i);
				calcPermute(lists, num, from + 1, to);
				swap(num, from, i);
			}
		}
	}
	public void swap(int[] num, int i, int j) {
		int temp;
		temp = num[i];
		num[i] = num[j];
		num[j] = temp;
	}
}
