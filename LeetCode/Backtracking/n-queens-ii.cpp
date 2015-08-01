#include <vector>
#include <string>
using std::vector;
using std::string;
// Runtime: 4 ms
// Best: 0 ms done

class Solution {
public:
	/*int totalNQueens(int n) {
		int count = 0;
		vector<int> arr(n, -1);
		solveNQueens(count, arr, 0, n);
		return count;
	}
	void solveNQueens(int &count, vector<int>& arr, int i, int n) {
		if (i == n) {
			count++;
			return;
		}
		for (int j = 0; j < n; j++) {
			if (isValid(arr, i, j, n)) {
				arr[i] = j;
				solveNQueens(count, arr, i + 1, n);
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
	}*/
	/*int totalNQueens(int n) {
		int count = 0;
		// [表达式含有常量值](http://blog.sina.com.cn/s/blog_7b83134b0101boli.html)
		// 0 ms
		//bool b1[2 * n - 1] = { false };
		//bool b2[n] = { false };
		//bool b3[2 * n - 1] = { false };

		// 8 ms...
		vector<bool> b1(2 * n - 1, false);
		vector<bool> b2(n, false);
		vector<bool> b3(2 * n - 1, false);
		solveNQueens(count, b1, b2, b3, 0, n);
		return count;
	}
	void solveNQueens(int& count, vector<bool>& b1, vector<bool>& b2, vector<bool>& b3, int i, int n) {
		if (i == n) {
			count++;
			return;
		}
		for (int j = 0; j < n; j++) {
			if (!b1[i + j] && !b2[j] && !b3[n - 1 + i - j]) {
				b1[i + j] = true;
				b2[j] = true;
				b3[n - 1 + i - j] = true;
				solveNQueens(count, b1, b2, b3, i + 1, n);
				b1[i + j] = false;
				b2[j] = false;
				b3[n - 1 + i - j] = false;
			}
		}
	}*/
	// 0 ms
	int totalNQueens(int n) {
		int count = 0;
		vector<int> b1(2 * n - 1, 0);
		vector<int> b2(n, 0);
		vector<int> b3(2 * n - 1, 0);
		solveNQueens(count, b1, b2, b3, 0, n);
		return count;
	}
	void solveNQueens(int& count, vector<int>& b1, vector<int>& b2, vector<int>& b3, int i, int n) {
		if (i == n) {
			count++;
			return;
		}
		for (int j = 0; j < n; j++) {
			if (b1[i + j] || b2[j] || b3[n - 1 + i - j]) {
				continue;
			}
			b1[i + j] = 1;
			b2[j] = 1;
			b3[n - 1 + i - j] = 1;
			solveNQueens(count, b1, b2, b3, i + 1, n);
			b1[i + j] = 0;
			b2[j] = 0;
			b3[n - 1 + i - j] = 0;
		}
	}
};