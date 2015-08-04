#include <string>
using std::string;
// Runtime: 76 ms
// we doesn't need a character c.
class TrieNode{
public:
	// Initialize your data structure here.
	TrieNode() : isWord(false) {
		memset(next, 0, sizeof(TrieNode*)* 26);
	}
	TrieNode(char _c) : c(_c), isWord(false) {
		memset(next, 0, sizeof(TrieNode*)* 26);
	}
	//~TrieNode() {
	//	delete []next;
	//}
	TrieNode* next[26];
	char c;
	bool isWord;
};
class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode();
	}
	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode* p = root;
		for (auto ch : word) {
			int index = ch - 'a';
			if (!p->next[index]) {
			//if (p->next[index] == nullptr) {
				p->next[index] = new TrieNode(ch);
			}
			p = p->next[index];
		}
		p->isWord = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return searchHelper(word.c_str(), root);
	}

private:
	//bool searchHelper(const char* word, TrieNode* node) {
	//	for (int i = 0; word[i]; i++) {
	//		if (node && word[i] != '.') {
	//			node = node->next[word[i] - 'a'];
	//		}
	//		else if (node && word[i] == '.') {
	//			for (int j = 0; j < 26; j++) {
	//				if (searchHelper(word + i + 1, node->next[j])) {
	//					return true;
	//				}
	//			}
	//			// 'a', search(".a") or search("a.")
	//			return false;
	//		}
	//		else {
	//			break;
	//		}
	//	}
	//	return node && node->isWord;
	//}
	bool searchHelper(const char* word, TrieNode* node) {
		// Runtime: 80 ms
		if (!node) {
			return false;
		}
		if (*word == '\0') {
			return node->isWord;
		}
		else if (*word == '.') {
			for (int j = 0; j < 26; j++) {
				if (searchHelper(word + 1, node->next[j])) {
					return true;
				}
			}
			return false;
		}
		else {
			return searchHelper(word + 1, node->next[*word - 'a']);
		}
	}
	TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");