#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
using std::swap;
// Runtime: 32 ms
// Best: 28 ms???
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		bt(ret, nums, nums.size(), 0);
		return ret;
	}
	void bt(vector<vector<int>> &ret, vector<int> nums, int size, int index) {
		if (index == size - 1) {
			ret.push_back(nums);
			return;
		}
		for (int i = index; i < size; ++i) {
			if (i != index && nums[i] == nums[index]) {
				continue;
			}
			swap(nums[index], nums[i]);
			bt(ret, nums, size, index + 1);
		}
	}
};