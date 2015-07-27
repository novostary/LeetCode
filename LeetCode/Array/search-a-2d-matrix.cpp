#include <vector>
using std::vector;
// Runtime: 16 ms
// Best: 12 ms done
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		int i = 0;
		int j = matrix[0].size() - 1;
		while (i < matrix.size() && j >= 0) {
			if (matrix[i][j] > target) {
				j--;
			}
			else if (matrix[i][j] < target) {
				i++;
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
		int begin = 0;
		int end = rowN * colN - 1;
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			int midValue = matrix[mid / colN][mid % colN];
			if (midValue == target) {
				return true;
			}
			else if (midValue < target) {
				begin = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		return false;
	}
	// Runtime: 12 ms
	bool searchMatrix3(vector<vector<int>>& matrix, int target) {
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
};