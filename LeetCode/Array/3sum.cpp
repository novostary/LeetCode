#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
// Runtime: 64 ms
// Best: 52 ms???
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3) {
			return res;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			for (int j = i + 1, k = nums.size() - 1; j < k;) {
				// 56 ms
				// int target = -nums[i];
				// int sum = nums[j] + nums[k];
				if (nums[i] + nums[j] + nums[k] == 0) {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					// more fast
					/*vector<int> temp(3, 0);
					temp[0] = nums[i];
					temp[1] = nums[j];
					temp[2] = nums[k];*/
					res.push_back(temp);
					j++;
					k--;
					while (j < k && nums[j] == nums[j - 1]) {
						j++;
					}
					while (j < k && nums[k] == nums[k + 1]) {
						k--;
					}
				}
				else if (nums[i] + nums[j] + nums[k] < 0) {
					j++;
				} 
				else {
					k--;
				}
			}
			while (i < nums.size() - 2 && nums[i] == nums[i + 1]) {
				i++;
			}
		}
		return res;
	}
};