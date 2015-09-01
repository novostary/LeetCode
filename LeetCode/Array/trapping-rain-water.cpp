#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
	int trap(vector<int>& height) { // Runtime: 8 ms
		int left = 0, right = height.size() - 1;
		int maxLeft = 0, maxRight = 0;
		int res = 0;
		// while (left <= right) {
		while (left < right) {
			if (height[left] <= height[right]) {
				if (height[left] >= maxLeft) {
					maxLeft = height[left];
				}
				else {
					res += maxLeft - height[left];
				}
				++left;
			}
			else {
				if (height[right] >= maxRight) {
					maxRight = height[right];
				}
				else {
					res += maxRight - height[right];
				}
				--right;
			}
		}
		return res;
	}

	int trap2(vector<int>& height) { // Runtime: 8 ms
		int left = 0, right = height.size() - 1;
		int level = 0, water = 0, lower = 0;
		while (left < right) {
			if (height[left] <= height[right]) {
				lower = height[left];
				++left;
			}
			else {
				lower = height[right];
				--right;
			}
			level = max(level, lower);
			water += level - lower;
		}
		return water;
	}
};