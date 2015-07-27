#include <vector>
using std::vector;
// Runtime: 16 ms
// Best: 12 ms??? 
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		vector<int> res(2, -1);
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid;
				while (left - 1 >= 0) {
					if (nums[left - 1] == target) {
						left--;
					}
					else {
						break;
					}
				}
				res[0] = left;

				right = mid;
				while (right + 1 < nums.size()) {
					if (nums[right + 1] == target) {
						right++;
					}
					else {
						break;
					}
				}
				res[1] = right;
				break;
			}
		}
		return res;
	}
	// Runtime: 16 ms sometimes 12 ms
	vector<int> searchRange2(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			int mid = (i + j) / 2;
			if (nums[mid] < target) {
				i = mid + 1;
			}
			else {
				j = mid;
			}
		}
		if (nums[i] == target) {
			res[0] = i;
		}
		else {
			return res;
		}
		j = nums.size() - 1;
		while (i < j) {
			int mid = (i + j) / 2 + 1;
			if (nums[mid] > target) {
				j = mid - 1;
			}
			else {
				i = mid;
			}
		}
		res[1] = j;
		return res;
	}
};