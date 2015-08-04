#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using std::string;
using std::vector;
using std::set;
using std::unordered_map;
// Runtime: 76 ms unordered_map
// Runtime: 84 ms set
// Best: 48 ms???
class TrieNode {
public:
	TrieNode() : isWord(false) {
		memset(next, 0, sizeof(TrieNode*)* 26);
	}
	TrieNode* next[26];
	bool isWord;
};

class Trie {
public:
	Trie() : maxlen(0) {
		root = new TrieNode();
	}
	void insert(string word) {
		TrieNode* p = root;
		for (auto ch : word) {
			if (!p->next[ch - 'a']) {
				p->next[ch - 'a'] = new TrieNode();
			}
			p = p->next[ch - 'a'];
		}
		p->isWord = true;
		if (word.size() > maxlen) {
			maxlen = word.size();
		}
	}
	void insert(vector<string>& words) {
		for (auto s : words) {
			insert(s);
		}
	}
	/*vector<string> findWords(vector<vector<char>>& board) {
		vector<string> ret;
		set<string> m;
		const int ROW = board.size();
		const int COL = board[0].size();
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				findWords(ret, string(), m, root, board, i, j, ROW, COL);
			}
		}
		return ret;
	}
	void findWords(vector<string>& ret, string s, set<string>& m, TrieNode* node, vector<vector<char>>&board, int i, int j, const int Row, const int Col) {
		// doesn't need count, because node->next[index] will be nullptr.
		if (board[i][j] == '.') {
			return;
		}
		int index = board[i][j] - 'a';
		if (node->next[index]) {
			if (node->next[index]->isWord) {
				if (m.find(s + board[i][j]) == m.end()) {
					ret.push_back(s + board[i][j]);
					m.insert(s + board[i][j]);
				}
			}
			char tmp = board[i][j];
			board[i][j] = '.';
			if (i > 0) {
				findWords(ret, s + tmp, m, node->next[index], board, i - 1, j, Row, Col);
			}
			if (i + 1 < Row) {
				findWords(ret, s + tmp, m, node->next[index], board, i + 1, j, Row, Col);
			}
			if (j > 0) {
				findWords(ret, s + tmp, m, node->next[index], board, i, j - 1, Row, Col);
			}
			if (j + 1 < Col) {
				findWords(ret, s + tmp, m, node->next[index], board, i, j + 1, Row, Col);
			}
			board[i][j] = tmp;
		}
	}*/
	vector<string> findWords(vector<vector<char>>& board) {
		vector<string> ret;
		unordered_map<string, int> m;
		const int ROW = board.size();
		const int COL = board[0].size();
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				findWords(ret, string(), m, root, board, i, j, ROW, COL);
			}
		}
		return ret;
	}
	void findWords(vector<string>& ret, string s, unordered_map<string, int>& m, TrieNode* node, vector<vector<char>>&board, int i, int j, const int Row, const int Col) {
		// doesn't need count, because node->next[index] will be nullptr.
		// 60 ms
		if (board[i][j] == '.') {
			return;
		}
		int index = board[i][j] - 'a';
		TrieNode* next = node->next[index];
		if (next) {
			char tmp = board[i][j];
			s += board[i][j];
			if (next->isWord) {
				if (m.find(s) == m.end()) {
					ret.push_back(s);
					m[s] = 1;
				}
			}
			board[i][j] = '.';
			if (i > 0) {
				findWords(ret, s, m, next, board, i - 1, j, Row, Col);
			}
			if (i + 1 < Row) {
				findWords(ret, s, m, next, board, i + 1, j, Row, Col);
			}
			if (j > 0) {
				findWords(ret, s, m, next, board, i, j - 1, Row, Col);
			}
			if (j + 1 < Col) {
				findWords(ret, s, m, next, board, i, j + 1, Row, Col);
			}
			board[i][j] = tmp;
		}
	}
private:
	TrieNode* root;
	int maxlen;
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ret;
		if (board.empty() || board[0].empty()) {
			return ret;
		}
		Trie trie;
		trie.insert(words);
		return trie.findWords(board);
	}
};