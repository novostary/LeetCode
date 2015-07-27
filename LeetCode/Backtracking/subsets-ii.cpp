#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
// Runtime: 12 ms
// Best: 8 ms??
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> curr;
		sort(nums.begin(), nums.end());
		backtracking(ret, curr, nums, 0);
		return ret;
	}
	void backtracking(vector<vector<int>> &ret, vector<int> curr, vector<int> &nums, int index) {
		ret.push_back(curr);
		for (int i = index; i < nums.size(); i++) {
			curr.push_back(nums[i]);
			backtracking(ret, curr, nums, i + 1);
			curr.pop_back();
			while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
				i++;
			}
		}
	}

	vector<vector<int>> subsetsWithDupIterative(vector<int>& nums) {
		vector<vector<int>> ret(1, vector<int>());
		vector<int> curr;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ) {
			int count = 1;
			while (i + count < nums.size() && nums[i] == nums[i + count]) {
				count++;
			}
			int size = ret.size();
			for (int j = 0; j < size; j++) {
				vector<int> curr = ret[j];
				for (int k = 0; k < count; k++) {
					curr.push_back(nums[i]);
					ret.push_back(curr);
				}
			}
			i += count;
		}
		return ret;
	}
};