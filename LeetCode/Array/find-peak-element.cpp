#include <vector>
using std::vector;
// Runtime: 8 ms
// Best: 4 ms???
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			int mid = i + (j - i) / 2;
			if (mid == 0 && nums[mid] > nums[mid + 1]) {
				return mid;
			}
			/*else if (mid == nums.size() - 1 && nums[mid] > nums[mid - 1]) {
				return mid;
			}*/
			else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
				return mid;
			}
			else if (nums[mid] > nums[mid + 1] && nums[mid] < nums[mid - 1]) {
				j = mid - 1;
			}
			else {
				i = mid + 1;
			}
		}
		return i;

		/*int n = nums.size();
		int i = 0, j = n - 1;
		while (i < j) {
			int mid = (j + i) >> 1;
			if (mid == 0 && nums[mid] > nums[mid + 1]) {
				return 0;
			}
			else if (nums[mid] > nums[mid + 1]) {
				if (nums[mid] > nums[mid - 1])
					return mid;
				else
					j = mid - 1;
			}
			else {
				i = mid + 1;
			}
		}
		return i;*/
	}
	int findPeakElement2(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;

		while (low < high)
		{
			int mid1 = (low + high) / 2;
			int mid2 = mid1 + 1;
			if (nums[mid1] < nums[mid2])
				low = mid2;
			else
				high = mid1;
		}
		return low;
	}
};