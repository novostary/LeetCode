#include <vector>
using std::vector;
// Runtime: 12 ms
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool rows[9][9] = { false };
		bool cols[9][9] = { false };
		bool blocks[3][3][9] = { false };
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '1';
					if (rows[i][num] || cols[j][num] || blocks[i / 3][j / 3][num]) {
						return false;
					}
					else {
						rows[i][num] = true;
						cols[j][num] = true;
						blocks[i / 3][j / 3][num] = true;
					}
				}
			}
		}
		return true;
	}
};