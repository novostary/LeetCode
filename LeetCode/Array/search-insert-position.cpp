#include <vector>
using std::vector;
// Runtime: 8 ms
// considering duplicates
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			int mid = (i + j) / 2;
			if (nums[mid] > target) {
				j = mid - 1;
			}
			else if (nums[mid] < target) {
				i = mid + 1;
			}
			else {
				return mid;
			}
		}
		return i;
	}

	int searchInsertWithDuplicates(vector<int>& nums, int target) {
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			int mid = (i + j) / 2;
			if (nums[mid] < target) {
				i = mid + 1;
			}
			else {
				j = mid - 1;
			}
		}
		return i;
	}
};