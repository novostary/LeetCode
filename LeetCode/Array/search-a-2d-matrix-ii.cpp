#include <vector>
using std::vector;
// Runtime: 312 ms
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		const int rowN = matrix.size();
		const int colN = matrix[0].size();
		int row = 0, col = colN - 1;
		while (row < rowN && col >= 0) {
			if (matrix[row][col] > target) {
				col--;
			}
			else if (matrix[row][col] < target) {
				row++;
			}
			else {
				return true;
			}
		}
		return false;
	}
	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		int rowN = matrix.size();
		int colN = matrix[0].size();
		int rBegin = 0, rEnd = rowN - 1;
		int cBegin = 0, cEnd = colN - 1;
		while (rBegin <= rEnd && cBegin <= cEnd) {
			int rMid = rBegin + (rEnd - rBegin) / 2;
			int cMid = cBegin + (cEnd - cBegin) / 2;
			if (matrix[rMid][cMid] < target) {
				if (matrix[rMid][colN - 1] < target) {
					rBegin = rMid + 1;
					cBegin = 0;
					cEnd = colN - 1;
				}
				else {
					rBegin = rMid;
					rEnd = rMid;
					cBegin = cMid + 1;
				}
			}
			else if (matrix[rMid][cMid] > target) {
				if (matrix[rMid][0] > target) {
					rEnd = rMid - 1;
					cBegin = 0;
					cEnd = colN - 1;
				}
				else {
					rBegin = rMid;
					rEnd = rMid;
					cEnd = cMid - 1;
				}
			}
			else {
				return true;
			}
		}
		return false;
	}
	// Runtime: 652 ms
	bool searchMatrix3(vector<vector<int>>& matrix, int target) {
		return searchMatrix(matrix, target, 0, matrix.size() - 1);
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target, int top, int bottom) {
		if (top > bottom)
			return false;

		int mid = top + (bottom - top) / 2;
		if (matrix[mid].front() <= target && target <= matrix[mid].back())
		if (searchVector(matrix[mid], target)) return true;

		if (searchMatrix(matrix, target, top, mid - 1)) return true;
		if (searchMatrix(matrix, target, mid + 1, bottom)) return true;

		return false;
	}

	bool searchVector(vector<int>& v, int target) {
		int left = 0, right = v.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (v[mid] == target)
				return true;
			if (v[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return false;
	}

};