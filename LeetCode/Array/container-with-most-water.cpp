#include <vector>
#include <algorithm>
using std::vector;
using std::min;
using std::max;
// https://leetcode.com/discuss/11482/yet-another-way-to-see-what-happens-in-the-o-n-algorithm
// https://leetcode.com/discuss/1074/anyone-who-has-a-o-n-algorithm
class Solution {
public:
	int maxArea(vector<int>& height) { // Runtime: 24 ms
		int i = 0, j = height.size() - 1;
		int maxarea = 0;
		while (i < j) {
			maxarea = max(maxarea, min(height[i], height[j]) * (j - i));
			if (height[i] < height[j]) {
				++i;
			}
			else {
				--j;
			}
		}
		return maxarea;
	}

	int maxArea2(vector<int>& height) { // Runtime: 24 ms
		int i = 0, j = height.size() - 1;
		int maxarea = 0;
		while (i < j) {
			int minheight = min(height[i], height[j]);
			maxarea = max(maxarea, minheight * (j - i));
			while (i < j && height[i] <= minheight) {
				++i;
			}
			while (i < j && height[j] <= minheight) {
				--j;
			}
		}
		return maxarea;
	}
};