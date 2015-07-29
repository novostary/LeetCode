#include <vector>
#include <string>
using std::vector;
using std::string;
// Runtime: 76 ms
// Best: 16 ms?? string word --> const string &word
class Solution {
public:
	/*bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty()) {
			if (word.empty()) {
				return true;
			}
			else {
				return false;
			}
		}
		vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (exist(board, used, word, i, j, 0)) {
					return true;
				}
			}
		}
		return false;
	}
	bool exist(vector<vector<char>>& board, vector<vector<bool>>& used, string word, int i, int j, int curr) {
		if (curr == word.size()) {
			return true;
		}
		if (!used[i][j] && board[i][j] == word[curr]) {

			used[i][j] = true;
			if (curr + 1 == word.size()) {
				return true;
			}
			if (i - 1 >= 0) {
				if (exist(board, used, word, i - 1, j, curr + 1)) {
					return true;
				}
			}
			if (i + 1 < board.size()) {
				if (exist(board, used, word, i + 1, j, curr + 1)) {
					return true;
				}
			}
			if (j - 1 >= 0) {
				if (exist(board, used, word, i, j - 1, curr + 1)) {
					return true;
				}
			}
			if (j + 1 < board[0].size()) {
				if (exist(board, used, word, i, j + 1, curr + 1)) {
					return true;
				}
			}
			used[i][j] = false;

		}
		return false;
	}*/

	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty()) {
			if (word.empty()) {
				return true;
			}
			else {
				return false;
			}
		}
		// vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
		const int ROW = board.size();
		const int COL = board[0].size();
		const int SLEN = word.size();
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (exist(board, word, i, j, 0, ROW, COL, SLEN)) {
					return true;
				}
			}
		}
		return false;
	}
	bool exist(vector<vector<char>>& board, const string &word, int i, int j, int curr, const int ROW, const int COL, const int SLEN) {
		if (board[i][j] != word[curr]) {
			return false;
		}
		else {
			if (curr + 1 == SLEN) {
				return true;
			}
			char tmp = board[i][j];
			board[i][j] = '.';
			if (i > 0 && exist(board, word, i - 1, j, curr + 1, ROW, COL, SLEN)) {
				return true;
			}
			if (i + 1 < ROW && exist(board, word, i + 1, j, curr + 1, ROW, COL, SLEN)) {
				return true;
			}
			if (j > 0 && exist(board, word, i, j - 1, curr + 1, ROW, COL, SLEN)) {
				return true;
			}
			if (j + 1 < COL && exist(board, word, i, j + 1, curr + 1, ROW, COL, SLEN)) {
				return true;
			}
			board[i][j] = tmp;
			return false;
		}
	}
};