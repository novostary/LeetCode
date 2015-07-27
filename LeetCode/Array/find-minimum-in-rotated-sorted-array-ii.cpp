#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
	int findMin(vector<int>& nums) {
		// Time Limit Exceeded
		int size = nums.size();
		if (size == 0) {
			return 0;
		}
		else if (size == 1)	{
			return nums[0];
		}
		else if (size == 2)	{
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
			else if (nums[mid] > nums[left]) {
				left = mid;
			}
			else {
				left++;
			}
		}
		return std::min(nums[left], nums[right]);

		/*int size = nums.size();

		if(size == 0) {
			return 0;
		} else if(size == 1) {
			return nums[0];
		} else if(size == 2) {
			return min(nums[0], nums[1]);
		}

		int start = 0;
		int stop = size - 1;

		while(start < stop - 1) {
			if(nums[start] < nums[stop]) {
				return nums[start];
			}

			int mid = start + (stop - start) / 2;
			if(nums[mid] > nums[start]) {
				start = mid;
			} else if(nums[mid] < nums[start]) {
				stop = mid;
			} else {
				start++;
			}
		}

		return min(nums[start], nums[stop]);*/
	}


};