#include <string>
using std::string;
// Runtime: 64 ms  Runtime: 56 ms
// https://leetcode.com/discuss/34832/two-c-o-n-solutions-array-or-hashtable
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() : isWord(false) {
		memset(next, 0, sizeof(TrieNode*)* 26);
	}
	TrieNode(char _c) : c(_c), isWord(false) {
		memset(next, 0, sizeof(TrieNode*)* 26);
	}
	~TrieNode() {
		delete []next;
	}
	TrieNode* next[26];
	char c;
	bool isWord;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	~Trie() {
		destroy(root);
	}
	void destroy(TrieNode* node) {
		for (int i = 0; i < 26; i++) {
			if (node->next[i]) {
				destroy(node->next[i]);
			}
		}
		delete node;
	}
	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* p = root;
		for (auto ch : word) {
			int index = ch - 'a';
			if (!p->next[index]) {
				p->next[index] = new TrieNode(ch);
			}
			p = p->next[index];
		}
		p->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* p = find(word);
		return p && p->isWord;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		return find(prefix) != nullptr;
	}

private:
	TrieNode* find(string key) {
		TrieNode* p = root;
		for (auto ch : key) {
			p = p->next[ch - 'a'];
			if (!p) {
				break;
			}
		}
		return p;
	}
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");