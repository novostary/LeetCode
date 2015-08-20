#include <vector>
#include <algorithm>
using std::vector;
using std::max;
// Runtime: 0 ms
class Solution {
public:
	int rob2(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
		for (int i = 1; i < nums.size(); i++) {
			int tmp1 = b1;
			b1 = max(nums[i] + a1, b1);
			a1 = tmp1;
		}
		for (int i = 2; i < nums.size() - 1; i++) {
			int tmp2 = b2;
			b2 = max(nums[i] + a2, b2);
			a2 = tmp2;
		}
		return max(b1, b2 + nums[0]);
	}

	int rob(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) {
			return size == 1 ? nums[0] : 0;
		}
		return max(rob(nums, 0, size - 2), rob(nums, 1, size - 1));
	}
private:
	int rob(vector<int>& nums, int i, int j) {
		int a = 0, b = 0;
		for (int k = i; k <= j; k++) {
			int tmp = b;
			b = max(nums[k] + a, b);
			a = tmp;
		}
		return b;
	}
};