#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
// Runtime: 0 ms
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ret;
		vector<int> curr;
		backtracking(ret, curr, k, n, 1);
		return ret;
	}
	void backtracking(vector<vector<int>> &ret, vector<int> curr, int k, int n, int level) {
		if (n == 0) {
			if (curr.size() == k) {
				ret.push_back(curr);
			}
			return;
		}
		else {
			for (int i = level; i < 10; ++i) {
				if (n < i) {
					return;
				}
				curr.push_back(i);
				backtracking(ret, curr, k, n - i, i + 1);
				curr.pop_back();
			}
		}
	}
};
