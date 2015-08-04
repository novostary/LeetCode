#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
// Runtime: 188 ms without deconstruct
// Runtime: 228 ms with deconstruct
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() : isWord(false) {

	}
	bool isWord;
	unordered_map<char, TrieNode*> next;
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
		for (auto entry : node->next) {
			destroy(entry.second);
		}
		delete node;
	}
	// Inserts a word into the trie.
	void insert(string word) {
		if (search(word)) {
			return;
		}
		TrieNode* p = root;
		for (auto ch : word) {
			if (p->next.find(ch) == p->next.end()) {
				p->next[ch] = new TrieNode();
			}
			p = p->next[ch];
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
			if (p->next.find(ch) == p->next.end()) {
				return nullptr;
			}
			p = p->next[ch];
		}
		return p;
	}
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");