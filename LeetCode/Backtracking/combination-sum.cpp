#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
// Runtime: 88 ms
// Best: 12 ms??  16 ms
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		if (candidates.empty() || target <= 0) {
			return ret;
		}
		vector<int> curr;
		sort(candidates.begin(), candidates.end());
		backtracking(ret, curr, candidates, target, 0);
		return ret;
	}
	// void backtracking(vector<vector<int>> &ret, vector<int> curr, vector<int> &candidates, int target, int level = 0) {
	void backtracking(vector<vector<int>> &ret, vector<int> curr, vector<int> &candidates, int target, int level) {
		if (target == 0) {
			ret.push_back(curr);
			return;
		}
		else if (target < 0) {
			return;
		}
		/*for (int i = level; i < candidates.size(); ++i) {
			target -= candidates[i];
			curr.push_back(candidates[i]);
			backtracking(ret, curr, candidates, target, i);
			curr.pop_back();
			target += candidates[i];
		}*/
		// 16 ms
		for (int i = level; i < candidates.size(); ++i) {
			if (target < candidates[i]) {
				break;
			}
			else if (target == candidates[i] || target >= 2 * candidates[i]) {
				curr.push_back(candidates[i]);
				backtracking(ret, curr, candidates, target - candidates[i], i);
				curr.pop_back();
			}
		}
	}
};