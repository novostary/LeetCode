#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;
// https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
// https://leetcode.com/discuss/38614/my-c-code-8ms-dp-o-n-2-time-o-n-space
// http://www.cnblogs.com/jcliBlogger/p/4548751.html

// Runtime: 20 ms
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
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

	int largestRectangleArea(vector<int>& height) {
		int size = height.size();
		int maxSquare = 0;
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
			int width = right[i] - left[i];
			if (height[i] > width) {
				maxSquare = max(maxSquare, width * width);
			}
			else {
				maxSquare = max(maxSquare, height[i] * height[i]);
			}
		}
		return maxSquare;
	}

	// Runtime: 12 ms
	int maximalSquareDP(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> len(row, vector<int>(col, 0));
		int maxS = 0;
		for (int j = 0; j < col; j++) {
			if (matrix[0][j] == '1') {
				len[0][j] = 1;
				maxS = 1;
			}
		}
		for (int i = 0; i < row; i++) {
			if (matrix[i][0] == '1') {
				len[i][0] = 1;
				maxS = 1;
			}
		}
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				if (matrix[i][j] == '1') {
					len[i][j] = min(len[i - 1][j], min(len[i][j - 1], len[i - 1][j - 1])) + 1;
					maxS = max(maxS, len[i][j]);
				}
			}
		}
		return maxS * maxS;
	}
};