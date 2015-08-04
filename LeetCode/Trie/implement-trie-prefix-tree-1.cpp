#include <string>
#include <vector>
using std::string;
using std::vector;
// Runtime: 108 ms
// Best: 52 ms??
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() : content(' '), isend(false), shared(0), children(vector<TrieNode*>(26, nullptr)) { }
	TrieNode(char ch) : content(ch), isend(false), shared(0), children(vector<TrieNode*>(26, nullptr)) { }
	TrieNode* subNode(char ch) {
		return children[ch - 'a'];
	}
	~TrieNode() {
		for (auto child : children) {
			delete child;
		}
	}
	char content;
	bool isend;
	int shared;
	vector<TrieNode*> children;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		if (search(word)) {
			return;
		}
		TrieNode* curr = root;
		for (auto ch : word) {
			TrieNode* child = curr->subNode(ch);
			if (child) {
				curr = child;
			}
			else {
				TrieNode *newNode = new TrieNode(ch);
				curr->children[ch - 'a'] = newNode;
				curr = newNode;
			}
			++curr->shared;
		}
		curr->isend = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* curr = root;
		for (auto ch : word) {
			curr = curr->subNode(ch);
			if (!curr) {
				return false;
			}
		}
		return curr->isend == true;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* curr = root;
		for (auto ch : prefix) {
			curr = curr->subNode(ch);
			if (!curr) {
				return false;
			}
		}
		return true;
	}
	~Trie() {
		delete root;
	}
private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");