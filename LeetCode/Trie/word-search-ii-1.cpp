#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using std::string;
using std::vector;
using std::set;
using std::unordered_map;
// Runtime: 52 ms void insert(string word, int i)
// Best: 48 ms  void insert(vector<string>& words, int i)
class TrieNode {
public:
	TrieNode() : isWord(false), isUsed(false), index(-1) {
		memset(next, 0, sizeof(TrieNode*)* 26);
	}
	TrieNode* next[26];
	bool isWord;
	bool isUsed;
	int index;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	void insert(string word, int i) {
		TrieNode* p = root;
		for (auto ch : word) {
			if (!p->next[ch - 'a']) {
				p->next[ch - 'a'] = new TrieNode();
			}
			p = p->next[ch - 'a'];
		}
		p->isWord = true;
		p->isUsed = false;
		p->index = i;
	}
	void insert(vector<string>& words, int i) {
		TrieNode* p = root;
		for (auto ch : words[i]) {
			if (!p->next[ch - 'a']) {
				p->next[ch - 'a'] = new TrieNode();
			}
			p = p->next[ch - 'a'];
		}
		p->isWord = true;
		p->isUsed = false;
		p->index = i;
	}
	void insert(vector<string>& words) {
		for (int i = 0; i < words.size(); i++) {
			// insert(words[i], i);
			insert(words, i);
		}
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ret;
		const int ROW = board.size();
		const int COL = board[0].size();
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				findWords(ret, words, root, board, i, j, ROW, COL);
			}
		}
		return ret;
	}
	void findWords(vector<string>& ret, vector<string>& words, TrieNode* node, vector<vector<char>>&board, int i, int j, const int Row, const int Col) {
		// doesn't need count, because node->next[index] will be nullptr.
		// 60 ms
		if (board[i][j] == '.') {
			return;
		}
		int index = board[i][j] - 'a';
		TrieNode* next = node->next[index];
		if (next) {
			char tmp = board[i][j];
			if (next->isWord && !next->isUsed) {
				ret.push_back(words[next->index]);
				next->isUsed = true;
			}
			board[i][j] = '.';
			if (i > 0) {
				findWords(ret, words, next, board, i - 1, j, Row, Col);
			}
			if (i + 1 < Row) {
				findWords(ret, words, next, board, i + 1, j, Row, Col);
			}
			if (j > 0) {
				findWords(ret, words, next, board, i, j - 1, Row, Col);
			}
			if (j + 1 < Col) {
				findWords(ret, words, next, board, i, j + 1, Row, Col);
			}
			board[i][j] = tmp;
		}
	}
private:
	TrieNode* root;
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
		return trie.findWords(board, words);
	}
};