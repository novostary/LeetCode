#include <vector>
#include <algorithm>
using std::vector;
using std::max;
// Runtime: 0 ms
class Solution {
public:
	int rob(vector<int>& nums) {
		int a = 0, b = 0;
		for (auto num : nums) {
			int tmp = b;
			b = max(num + a, b);
			a = tmp;
		}
		return b;
	}

	int rob2(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int size = nums.size();
		if (size == 1) {
			return nums[0];
		}
		if (size == 2) {
			return max(nums[0], nums[1]);
		}
		// int ret[size];
		int *ret = new int[size];
		ret[0] = nums[0];
		ret[1] = max(nums[1], ret[0]);
		for (int i = 2; i < size; i++) {
			ret[i] = max(nums[i] + ret[i - 2], ret[i - 1]);
		}
		return ret[size - 1];
	}
};