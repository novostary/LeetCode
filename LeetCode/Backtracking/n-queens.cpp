#include <vector>
#include <string>
using std::vector;
using std::string;
// Runtime: 8 ms
// Best: 4 ms??
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ret;
		if (n < 1) {
			return ret;
		}
		vector<string> solu(n, string(n, '.'));
		vector<int> arr(n, -1);
		solveNQueens(ret, solu, arr, 0, n);
		// bool stat[n] = {false};
		// solveNQueens(ret, solu, stat, 0, n);
		return ret;
	}
	void solveNQueens(vector<vector<string>>& ret, vector<string>& solu, vector<int>& arr, int i, int n) {
		if (i == n) {
			for (int k = 0; k < n; k++) {
				solu[k][arr[k]] = 'Q';
			}
			ret.push_back(solu);
			for (int k = 0; k < n; k++) {
				solu[k][arr[k]] = '.';
			}
			return;
		}
		for (int j = 0; j < n; j++) {
			if (solu[i][j] == '.' && isValid(arr, i, j, n)) {
				//solu[i][j] = 'Q';
				arr[i] = j;
				solveNQueens(ret, solu, arr, i + 1, n);
				// arr[i] = -1;
				//solu[i][j] = '.';
			}
		}
	}
	bool isValid(vector<int>& arr, int i, int j, int n) {
		for (int l = j - 1, m = i - 1, r = j + 1; m >= 0; l--, m--, r++) {
			int check = arr[m];
			if (check == l || check == j || check == r) {
				return false;
			}
		}
		return true;
	}
	/*void solveNQueens(vector<vector<string>>& ret, vector<string>& solu, bool stat[], int i, int n) {
	if (i == n) {
	ret.push_back(solu);
	return;
	}
	for (int j = 0; j < n; j++) {
	if (!stat[j]) {
	solu[i][j] = 'Q';
	stat[j] = true;
	solveNQueens(ret, solu, stat, i + 1, n);
	stat[j] = false;
	solu[i][j] = '.';
	}
	}
	}
	void solveNQueens(vector<vector<string>>& ret, vector<string>& solu, int i, int n) {
	if (i == n) {
	ret.push_back(solu);
	return;
	}
	for (int j = 0; j < n; j++) {
	if (solu[i][j] == '.' && isValid(solu, i, j, n)) {
	solu[i][j] = 'Q';
	solveNQueens(ret, solu, i + 1, n);
	solu[i][j] = '.';
	}
	}
	}
	bool isValid(vector<string>& solu, int i, int j, int n) {
	for (int k = 0; k < i; k++) {
	if (solu[k][j] == 'Q') {
	return false;
	}
	}
	for (int k = j - 1; k >= 0 && i - j + k >= 0; k--) {
	if (solu[i - j + k][k] == 'Q') {
	return false;
	}
	}
	for (int k = j + 1; k < n && i + j - k >= 0; k++) {
	if (solu[i + j - k][k] == 'Q') {
	return false;
	}
	}
	return true;
	}*/
};