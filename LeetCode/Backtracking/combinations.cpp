#include <vector>
using std::vector;
// Runtime: 16 ms
// Best: 8 ms done
// https://leetcode.com/discuss/47542/iteration-solution-without-recursive-stack-lines-pointer
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ret;
		if (n <= 0 || k <= 0 || k > n) {
			return ret;
		}
		vector<int> curr;
		DFS(ret, curr, n, k, 1);
		return ret;
	}
	void DFS(vector<vector<int>> &ret, vector<int> curr, int n, int k, int level) {
		if (curr.size() == k) {
			ret.push_back(curr);
			return;
		}
		for (int i = level; i <= n && curr.size() < k; i++) {
			curr.push_back(i);
			DFS(ret, curr, n, k, i + 1);
			curr.pop_back();
		}
	}

	vector<vector<int>> combine8ms(int n, int k) {
		vector<vector<int>> ret;
		vector<int> curr(k, 0);
		int level = 0;
		int maxLevel = k - 1;
		int level0Max = n - k + 1;
		while (level >= 0) {
			if (++curr[level] > level0Max + level) {
				--level;
			}
			else if (level == maxLevel) {
				ret.push_back(curr);
			}
			else {
				curr[level + 1] = curr[level];
				level = level + 1;
			}
		}
		return ret;
	}
};