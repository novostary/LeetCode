#include <vector>
#include <algorithm>
using std::swap;
using std::vector;
// Runtime: 16 ms
// Best: 12 ms???
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ret;
		bt(ret, nums, 0);
		return ret;
	}
	void bt(vector<vector<int>> &ret, vector<int> &nums, int index) {
		if (index == nums.size()) {
			ret.push_back(nums);
		}
		for (int i = index; i < nums.size(); ++i) {
			swap(nums[index], nums[i]);
			bt(ret, nums, index + 1);
			swap(nums[index], nums[i]);
		}
	}
	// same address...
	/*void swap(int &a, int &b) {
		int tmp = b;
		b = a;
		a = tmp;
	}*/
};