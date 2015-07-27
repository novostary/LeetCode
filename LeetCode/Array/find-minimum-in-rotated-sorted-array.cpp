#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) {
			return 0;
		}
		else if (size == 1) {
			return nums[0];
		}
		else if (size == 2) {
			return std::min(nums[0], nums[1]);
		}
		int left = 0;
		int right = size - 1;
		while (left < right - 1) {
			if (nums[left] < nums[right]) {
				return nums[left];
			}
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[left]) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		return std::min(nums[left], nums[right]);
	}
};