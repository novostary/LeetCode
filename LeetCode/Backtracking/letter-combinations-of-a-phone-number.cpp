#include <string>
#include <vector>
using std::string;
using std::vector;
// Runtime: 0 ms
// Input: ""
// Output: [""]
// Expected :	[]
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> dic;
		dic.push_back("");
		dic.push_back("");
		dic.push_back("abc");
		dic.push_back("def");
		dic.push_back("ghi");
		dic.push_back("jkl");
		dic.push_back("mno");
		dic.push_back("pqrs");
		dic.push_back("tuv");
		dic.push_back("wxyz");

		vector<string> ret;
		if (digits == "") {
			return ret;
		}
		string tmp;
		backtracking(ret, tmp, dic, digits, 0);
		return ret;
	}
	void backtracking(vector<string> &ret, string tmp, vector<string> &dic, string digits, int level) {
		if (level == digits.size()) {
			ret.push_back(tmp);
			return;
		}
		int index = digits[level] - '0';
		for (int i = 0; i < dic[index].size(); ++i) {
			tmp.push_back(dic[index][i]);
			backtracking(ret, tmp, dic, digits, level + 1);
			tmp.pop_back();
		}
	}
};