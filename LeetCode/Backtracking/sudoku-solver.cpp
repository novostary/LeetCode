#include <vector>
using std::vector;
// Runtime: 4 ms
// https://leetcode.com/discuss/31852/clean-c-code-using-backtrace-easy-to-understand
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		bool rows[9][9] = { false };
		bool cols[9][9] = { false };
		bool blocks[3][3][9] = { false };
		initSudoku(rows, cols, blocks, board);
		solveSudoku(board, rows, cols, blocks, 0, 0);
	}
	void initSudoku(bool rows[][9], bool cols[][9], bool blocks[][3][9], vector<vector<char>> &board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '1';
					rows[i][num] = true;
					cols[j][num] = true;
					blocks[i / 3][j / 3][num] = true;
				}
			}
		}
	}
	bool solveSudoku(vector<vector<char>> &board, bool rows[][9], bool cols[][9], bool blocks[][3][9], int row, int col) {
		if (board.size() == row) {
			return true;
		}
		if (board[row][col] != '.') {
			if (col >= board.size() - 1) {
				return solveSudoku(board, rows, cols, blocks, row + 1, 0);
			}
			else {
				return solveSudoku(board, rows, cols, blocks, row, col + 1);
			}
		}
		else {
			for (int i = 0; i < 9; i++) {
				if (rows[row][i] || cols[col][i] || blocks[row / 3][col / 3][i]) {
					continue;
				}
				else {
					board[row][col] = i + '1';
					rows[row][i] = true;
					cols[col][i] = true;
					blocks[row / 3][col / 3][i] = true;
					// col can be 9 if solveSudoku returns false
					/* if (col >= board.size() - 1 && solveSudoku(board, rows, cols, blocks, row + 1, 0)) {
						return true;
					}*/
					if (col >= board.size() - 1) {
						if (solveSudoku(board, rows, cols, blocks, row + 1, 0)) {
							return true;
						}
					}
					else if (solveSudoku(board, rows, cols, blocks, row, col + 1)) {
						return true;
					}
					board[row][col] = '.';
					rows[row][i] = false;
					cols[col][i] = false;
					blocks[row / 3][col / 3][i] = false;
				}
			}
			return false;
		}
	}
};