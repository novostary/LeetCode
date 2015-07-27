#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;
using std::fill_n;
// Runtime: 16 ms
// Best: 12 ms???
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int row = matrix.size();
		int col = matrix[0].size();
		int maxR = 0;
		vector<int> height(col, 0);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == '1') {
					height[j]++;
				}
				else {
					height[j] = 0;
				}
			}
			maxR = max(maxR, largestRectangleArea(height));
		}
		return maxR;
	}

	// Runtime: 16 ms DP
	int largestRectangleArea(vector<int>& height) {
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

	// 12 ms
	/*int maximalRectangle2(vector<vector<char>>& matrix) {
		if (matrix.empty()) 
			return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();
		// int left[n], right[n], height[n];
		int *left = new int[n];
		int *right = new int[n];
		int *height = new int[n];
		fill_n(left, n, 0); 
		fill_n(right, n, n); 
		fill_n(height, n, 0);
		int maxA = 0;
		for (int i = 0; i<m; i++) {
			int cur_left = 0, cur_right = n;
			for (int j = 0; j<n; j++) { // compute height (can do this from either side)
				if (matrix[i][j] == '1') 
					height[j]++;
				else 
					height[j] = 0;
			}
			for (int j = 0; j<n; j++) { // compute left (from left to right)
				if (matrix[i][j] == '1') 
					left[j] = max(left[j], cur_left);
				else { 
					left[j] = 0; 
					cur_left = j + 1; 
				}
			}
			// compute right (from right to left)
			for (int j = n - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') 
					right[j] = min(right[j], cur_right);
				else { 
					right[j] = n; 
					cur_right = j; 
				}
			}
			// compute the area of rectangle (can do this from either side)
			for (int j = 0; j<n; j++)
				maxA = max(maxA, (right[j] - left[j])*height[j]);
		}
		return maxA;
	}*/
};