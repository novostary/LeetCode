#include <vector>
#include <string>
using std::vector;
using std::string;
// Runtime: 12 ms
// void bt(vector<vector<string>>& ret, vector<string>& curr, const string& s, int index) // Runtime: 52 ms
// bool isPalindrome(const string& s, int i, int j) // Runtime: 24 ms
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ret;
		vector<string> curr;
		bt(ret, curr, s, 0);
		return ret;
	}
	void bt(vector<vector<string>>& ret, vector<string>& curr, const string& s, int index) {
		if (index == s.size()) {
			ret.push_back(curr);
			return;
		}
		for (int i = index; i < s.size(); i++) {
			if (isPalindrome(s, index, i)) {
				curr.push_back(s.substr(index, i - index + 1));
				bt(ret, curr, s, i + 1);
				curr.pop_back();
			}
		}
	}
	bool isPalindrome(const string& s, int i, int j) {
		while (i < j) {
			if (s[i] != s[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};