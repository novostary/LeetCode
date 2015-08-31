#include <vector>
#include <algorithm>
using std::vector;
using std::min;
// https://leetcode.com/discuss/42143/4ms-solution-and-nlogn-solution-with-detailed-explanations ∏¥‘”∂»∑÷Œˆ
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) { // Runtime: 4 ms
		int minimal = INT_MAX;
		int left = 0, right = 0, sum = 0;
		while (right < nums.size()) {
			// move right silder forward till total >= s
			do {
				sum += nums[right++];
			} while (right < nums.size() && sum < s);
			// move left slider forward while maintaining total >= s
			while (left < right && sum - nums[left] >= s) {
				sum -= nums[left++];
			}
			// record if it's the minimum
			if (sum >= s) {
				minimal = min(minimal, right - left);
			}
		}
		return minimal == INT_MAX ? 0 : minimal;
	}

	int minSubArrayLen1(int s, vector<int>& nums) { // Runtime: 4 ms
		int minimal = INT_MAX;
		int firstPos = 0;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			while (sum >= s) {
				minimal = min(minimal, i - firstPos + 1);
				sum -= nums[firstPos++];
			}
		}
		return minimal == INT_MAX ? 0 : minimal;
	}

	int minSubArrayLen2(int s, vector<int>& nums) { // Runtime: 4 ms
		if (nums.empty()) {
			return 0;
		}
		int minimal = INT_MAX;
		int i = 0, j = 0;
		int sum = 0;
		while (j < nums.size()) {
			sum += nums[j];
			if (sum >= s) {
				minimal = min(minimal, j - i + 1);
				if (minimal == 1) {
					return 1;
				}
				sum -= nums[i];
				++i;
				sum -= nums[j];
			}
			else {
				++j;
			}
		}
		return minimal == INT_MAX ? 0 : minimal;
	}
};