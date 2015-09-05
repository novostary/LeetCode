#include <vector>
#include <algorithm>
#include <stack>
using std::vector;
using std::max;
using std::min;
using std::stack;
// http://blog.csdn.net/viclao/article/details/41909595 Stack
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

	// Stack
	int trap3(vector<int>& height) { // Runtime: 12 ms
		if (height.size() < 3) {
			return 0;
		}
		int water = 0, i = 0;
		stack<int> s;
		while (i < height.size()) {
			if (s.empty() || height[s.top()] >= height[i]) {
				s.push(i++);
			}
			else {
				int bottom = height[s.top()];
				s.pop();
				if (!s.empty()) {
					int high = min(height[i], height[s.top()]);
					int length = i - s.top() - 1;
					water += (high - bottom) * length;
				}
			}
		}
		return water;
	}
};