# 数组的全排列 #
## 问题描述 ##
[permutations](https://oj.leetcode.com/problems/permutations/)

Given a collection of numbers, return all possible permutations.
 
[permutations-ii](https://oj.leetcode.com/problems/permutations-ii/)
 
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

[next-permutation](https://oj.leetcode.com/problems/next-permutation/)
 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

### 分析 ###
1. 边界条件：输入为空，或者数组的长度为1
2. 是否有重复的数字
3. Next Permutation中如果输入为降序，如何定义下一个排列？
## 测试用例 ##
1. 数组为空
2. 数组的长度为1
3. 12453
4. 12345
5. 112233
6. 211233
7. 332211
8. 11
## 核心思想 ##
### 递归 ###
先排第一个位置，再排后面的位置。

注意：

递归思想仅针对无重复元素的情况。

如果输入无序的话，输出亦无序。
### 如何处理重复的情况 ###
借助于字典序排列的想法，把数组从小到大来排列，最后一个为所有元素的降序排列。本质就是解决Next Permutation的问题。

12345-->12354

12354-->12435

12435-->12453

12453-->12534

12534-->12543

12543-->13245

观察规律，有种十进制进位的感觉。

123**45**-->123**54**

12**3**5**4**-->124**53**-->124**35**

124**35**-->124**53**

12**45**3-->125**43**-->125**34**

125**34**-->125**43**

1**2**54**3**-->13**542**-->13**245**

1. 从右往左看，找到第一个升序(num_i, num_j)，因为是升序，num_i之后至少有一个数字比它大，找到最小的比它大的数字（也即从右往左看第一个比它大的数字，因为它后面的数字为降序排列）。
2. 交换两者的位置，第i个位置之后的排列依旧是一个降序排列，对其翻转即可得到Next Permutation。
## 需要考虑的细节 ##
1. LeetCode中要求返回的是类型为List<List<Integer>>的链表，可通过如下方式对其进行初始化。（Java）

	List<List<Integer>> lists = new ArrayList<List<Integer>>();

2. Java中对于数组的排序函数，升序。

	void java.util.Arrays.sort(int[] a)
## 源码 ##
	// 通用函数，交换两个元素的位置
	public void swap(int[] num, int i, int j) {
		int temp;
		temp = num[i];
		num[i] = num[j];
		num[j] = temp;
	}
	// 通用函数，数组翻转
	public void reverse(int[] num, int from, int to) {
		while (from < to) {
			swap(num, from, to);
			from++;
			to--;
		}
	}
	// 440 ms，递归法
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
	// Runtime: 420 ms, Next Permutation
	public void nextPermutation(int[] num) {
		if (num == null || num.length <= 1)
			return;
		int next;
		for (next = num.length - 2; next >= 0; next--) {
			if (num[next] < num[next + 1]) {
				break;
			}
		}
		if (next < 0) {
			reverse(num, 0, num.length - 1);
			return;
		}
		for (int i = num.length - 1; i >= 0; i--) {
			if (num[next] < num[i]) {
				swap(num, next, i);
				break;
			}
		}
		reverse(num, next + 1, num.length - 1);
	}
	// 512 ms, permutations II
	public List<List<Integer>> permuteUnique(int[] num) {
        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        List<Integer> l;
        Arrays.sort(num);
        boolean hasNext = true;
        while(hasNext == true) {
        	l = new ArrayList<Integer>();
        	for (int i = 0; i < num.length; i++) {
        		l.add(num[i]);
        	}
        	lists.add(l);
        	hasNext = nextPermutationUnique(num);
        }
        return lists;
    }
	// 与nextPermutation相比增加了返回值
	public boolean nextPermutationUnique(int[] num) {
		if (num == null || num.length <= 1)
			return false;
		int next;
		for (next = num.length - 2; next >= 0; next--) {
			if (num[next] < num[next + 1]) {
				break;
			}
		}
		if (next < 0) {
			// reverse(num, 0, num.length - 1);
			return false;
		}
		for (int i = num.length - 1; i >= 0; i--) {
			if (num[next] < num[i]) {
				swap(num, next, i);
				break;
			}
		}
		reverse(num, next + 1, num.length - 1);
		return true;
	}
	// 388 ms, 见拓展部分
	// https://oj.leetcode.com/problems/permutation-sequence/
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
## 拓展 ##
### N个元素所有长度为k的排列 ###
有重复元素和没有重复元素。

没有重复元素递归即可，需要注意递归的深度。

如果有重复元素，类比next Permutation的计算方法。首先确定所有升序的长度为k的排列（该过程也可以借鉴next Permutation的思路），然后对每个这样的排列进行全排列。
### Previous permutation ###
与next permutation相对应。
### Permutation Sequence ###
[permutation-sequence](https://oj.leetcode.com/problems/permutation-sequence/)
 
寻找n个元素所构成的全排列中的第k个全排列。

假设没有重复元素。每一个排列与其对应的编号是一一对应的。因此，给出编号求排列或者给出排列求编号都是可以行。注意，在实际运算中，编号应从0开始。

123—1—0

132—2—1

213—3—2

231—4—3

312—5—4

321—6—5

核心思想为分类。第一个位置的元素有n中可能，那么如何确定第一个位置的元素是多少呢？(k-1)/(n-1)!，确定第一个位置后，问题转化为n-1个元素的全排列，第(k-1)%(n-1)!+1个排列是多少。可以通过递归或者循环来实现。

需要注意的是，已经出现的元素不能重复出现，可以考虑创建一个包含n个元素的链表，每确定一个元素，则从这个链表中将其删除。详见源码部分。

解决这个问题的方法称为[康托（Cantor）展开、康托逆展开](http://blog.csdn.net/zhongkeli/article/details/6966805)。
### Wikipedia ###
[Permutation](http://en.wikipedia.org/wiki/Permutation)
