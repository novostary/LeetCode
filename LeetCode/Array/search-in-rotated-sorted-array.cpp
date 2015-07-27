#include <vector>
#include <algorithm>
using std::vector;
using std::min;
// Runtime: 4 ms
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int size = nums.size();
		if (size == 0) {
			return -1;
		}
		else if (size == 1) {
			if (nums[0] == target) {
				return 0;
			}
			else {
				return -1;
			}
		}
		int left = 0;
		int right = size - 1;
		while (left < right - 1) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] < target) {
				if (nums[left] < nums[mid] || (nums[mid] < nums[right] && target <= nums[right])) {
					left = mid;
				}
				else {
					right = mid;
				}
			}
			else {
				if ((nums[left] < nums[mid] && target >= nums[left]) || nums[mid] < nums[right]) {
					right = mid;
				}
				else {
					left = mid;
				}
			}
		}
		if (nums[left] == target) {
			return left;
		}
		else if (nums[right] == target) {
			return right;
		}
		else {
			return -1;
		}
	}
};