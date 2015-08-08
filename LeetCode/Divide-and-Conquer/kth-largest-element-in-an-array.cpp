#include <vector>
using std::vector;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (k < 1 || k > nums.size()) {
			return 0;
		}
		int i = 0, j = nums.size() - 1;
		while (true) {
			int pos = partition(nums, i, j);
			if (pos == -1) {
				return 0;
			}
			if (pos + 1 == k) {
				return nums[pos];
			}
			else if (pos + 1 > k) {
				j = pos - 1;
			}
			else {
				i = pos + 1;
				//k = k - (pos + 1);
			}
		}
	}
	int partition(vector<int>& nums, int i, int j) {
		if (i > j) {
			return -1;
		}
		int target = nums[i];
		int l = i, r = j;
		while (l < r) {
			while (l < r && nums[r] < target) {
				r--;
			}
			if (l < r) {
				nums[l] = nums[r];
				l++;
			}
			while (l < r && nums[l] >= target) {
				l++;
			}
			if (l < r) {
				nums[r] = nums[l];
				r--;
			}
		}
		nums[l] = target;
		return l;
	}
};