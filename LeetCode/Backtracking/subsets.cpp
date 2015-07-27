#include <algorithm>
#include <vector>
using std::sort;
using std::vector;
// 8 ms
// Best: 4 ms Iterative
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		vector<int> curr;
		if (nums.empty()) {
			ret.push_back(curr);
			return ret;
		}
		backtracking(ret, curr, nums, 0);
		return ret;
	}
	void backtracking(vector<vector<int>> &ret, vector<int> curr, vector<int> &nums, int index) {
		if (index == nums.size()) {
			ret.push_back(curr);
			return;
		}
		ret.push_back(curr);
		for (int i = index; i < nums.size(); ++i) {
			curr.push_back(nums[i]);
			backtracking(ret, curr, nums, i + 1);
			curr.pop_back();
		}
	}

	vector<vector<int>> subsets2(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		vector<int> curr;
		backtracking2(ret, curr, nums, 0);
		return ret;
	}
	void backtracking2(vector<vector<int>> &ret, vector<int> curr, vector<int> &nums, int index) {
		ret.push_back(curr);
		for (int i = index; i < nums.size(); ++i) {
			curr.push_back(nums[i]);
			backtracking2(ret, curr, nums, i + 1);
			curr.pop_back();
		}
	}
	// 4 ms
	vector<vector<int>> subsetsIterative(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> subs(1, vector<int>());
		for (int i = 0; i < nums.size(); i++) {
			int n = subs.size();
			for (int j = 0; j < n; j++) {
				subs.push_back(subs[j]);
				subs.back().push_back(nums[i]);
			}
		}
		return subs;
	}
	// 12 ms
	vector<vector<int>> subsetsBitManipulation(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int num_subset = pow(2, nums.size());
		vector<vector<int> > res(num_subset, vector<int>());
		for (int i = 0; i < nums.size(); i++)
		for (int j = 0; j < num_subset; j++)
		if ((j >> i) & 1)
			res[j].push_back(nums[i]);
		return res;
	}
	// Runtime: 8 ms
	vector<vector<int>> subsetsBitManipulation2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int num_subset = pow(2, nums.size());
		vector<vector<int> > res(num_subset, vector<int>());
		for (int i = 0; i < nums.size(); i++)
			for (int step = 1 << i, start = 0; start < num_subset; start += 2 * step)
				for (int j = start; j < start + step; j++)
					res[j].push_back(nums[i]);
		return res;
	}
};