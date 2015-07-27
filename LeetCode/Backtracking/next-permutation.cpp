#include <vector>
#include <algorithm>
using std::vector;
using std::swap;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int next;
		for (next = nums.size() - 2; next >= 0; next--) {
			if (nums[next] < nums[next + 1]) {
				break;
			}
		}
		if (next < 0) {
			reverse(nums, 0, nums.size() - 1);
			return;
		}
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[next] < nums[i]) {
				swap(nums[next], nums[i]);
				break;
			}
		}
		reverse(nums, next + 1, nums.size() - 1);
	}
	void reverse(vector<int>& nums, int from, int to) {
		while (from < to) {
			swap(nums[from], nums[to]);
			from++;
			to--;
		}
	}
};