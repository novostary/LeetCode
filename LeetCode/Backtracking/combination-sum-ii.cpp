#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
// Runtime: 12 ms
// Best: 8 ms?? know
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		if (candidates.empty() || target <= 0) {
			return ret;
		}
		sort(candidates.begin(), candidates.end());
		vector<int> curr;
		backtracking(ret, curr, candidates, target);
		return ret;
	}
	void backtracking(vector<vector<int>> &ret, vector<int> curr, vector<int> &candidates, int target, int level = 0) {
		if (target == 0) {
			ret.push_back(curr);
			return;
		}
		else {
			for (int i = level; i < candidates.size(); ++i) {
				if (i > level && candidates[i] == candidates[i - 1]) {
					continue;
				}
				if (target < candidates[i]) {
					break;
				}
				curr.push_back(candidates[i]);
				backtracking(ret, curr, candidates, target - candidates[i], i + 1);
				curr.pop_back();
			}
		}
	}
	// 8 ms
	vector<vector<int>> combinationSum2_2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> current;
		sort(candidates.begin(), candidates.end());
		backTracking(candidates.begin(), current, res, candidates, target);
		return res;
	}

	void backTracking(vector<int>::iterator n, vector<int>& current, vector<vector<int>>& res, const vector<int>& candidates, int target){
		if (!target) res.push_back(current);
		else if (target>0){
			for (; n != candidates.end() && *n <= target; ++n){
				current.push_back(*n);
				backTracking(n + 1, current, res, candidates, target - *n);
				current.pop_back();
				while (n + 1 != candidates.end() && *(n + 1) == *n) ++n;
			}
		}
	}
};