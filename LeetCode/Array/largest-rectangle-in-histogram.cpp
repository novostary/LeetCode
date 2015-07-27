#include <vector>
#include <algorithm>
using std::vector;
using std::max;
// Runtime: 28 ms
// Best: 16 ms
class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		height.push_back(0);
		vector<int> s;
		int maxArea = 0;
		for (int i = 0; i < height.size(); ) {
			if (s.empty() || height[s.back()] < height[i]) {
				s.push_back(i);
				i++;
			}
			else {
				int t = s.back();
				s.pop_back();
				maxArea = max(maxArea, height[t] * (s.empty() ? i : i - s.back() - 1));
			}
		}
		return maxArea;
	}
	// Runtime: 16 ms DP
	int largestRectangleArea2(vector<int>& height) {
		int size = height.size();
		int maxArea = 0;
		vector<int> left(size, 0);
		vector<int> right(size, size);
		for (int i = 1; i < size; i++) {
			int p = i - 1;
			while (p >= 0 && height[i] <= height[p]) {
				p = left[p] - 1;
			}
			left[i] = p + 1;
		}
		for (int i = size - 2; i >= 0; i--) {
			int p = i + 1;
			while (p < size && height[i] <= height[p]) {
				p = right[p];
			}
			right[i] = p;
		}
		for (int i = 0; i < size; i++) {
			maxArea = max(maxArea, height[i] * (right[i] - left[i]));
		}
		return maxArea;
	}
};