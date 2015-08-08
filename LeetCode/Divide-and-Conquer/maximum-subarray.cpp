#include <vector>
#include <algorithm>
using std::vector;
using std::max;
// Runtime: 8 ms
struct val {
	int leftsum;
	int rightsum;
	int fullsum;
	int maxsum;
	val(int l, int r, int f, int m) : leftsum(l), rightsum(r), fullsum(f), maxsum(m) {}
};
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int cur = nums[0];
		int sum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (cur > 0) {
				cur += nums[i];
			}
			else {
				cur = nums[i];
			}
			sum = max(sum, cur);
		}
		return sum;
	}

	int maxSubArray2(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int cur = 0;
		int sum = INT_MIN;
		for (auto x: nums) {
			if (cur > 0) {
				cur += x;
			}
			else {
				cur = x;
			}
			sum = max(sum, cur);
		}
		return sum;
	}

	// Runtime: 12 ms
	int maxSubArray3(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int leftsum, rightsum, fullsum;
		return maxSubArray(nums, 0, nums.size() - 1, leftsum, rightsum, fullsum);
	}
	int maxSubArray(vector<int>& nums, int i, int j, int& leftsum, int& rightsum, int& fullsum) {
		if (i == j) {
			leftsum = nums[i];
			rightsum = nums[i];
			fullsum = nums[i];
			return nums[i];
		}
		int l1, s1, r1, f1, l2, s2, r2, f2;
		s1 = maxSubArray(nums, i, (i + j) / 2, l1, r1, f1);
		s2 = maxSubArray(nums, (i + j) / 2 + 1, j, l2, r2, f2);
		leftsum = max(l1, f1 + l2);
		rightsum = max(r2, f2 + r1);
		fullsum = f1 + f2;
		return max(s1, max(s2, r1 + l2));
	}
};