#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
// Runtime: 20 ms
// Best: 12 ms - remove duplicates
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) {
			return -1;
		}
		int res = 0;
		sort(nums.begin(), nums.end());
		int distance = INT_MAX;
		for (int i = 0; i < nums.size() - 2; i++) {
			// 12 ms
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				int tmpVal = nums[i] + nums[j] + nums[k];
				if (tmpVal < target) {
					int tmpDistance = target - tmpVal;
					if (tmpDistance < distance) {
						distance = tmpDistance;
						res = tmpVal;
					}
					j++;
				}
				else if (tmpVal > target) {
					int tmpDistance = tmpVal - target;
					if (tmpDistance < distance) {
						distance = tmpDistance;
						res = tmpVal;
					}
					k--;
				}
				else {
					return target;
				}
			}
		}
		return res;
	}
};