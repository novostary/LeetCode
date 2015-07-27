#include <string>
#include <vector>
using std::string;
using std::vector;
// 0 ms
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		DFS(ret, "", n, n);
		return ret;
	}
	void DFS(vector<string> &ret, string s, int lLeft, int rLeft) {
		if (lLeft <= 0) {
			ret.push_back(s + string(rLeft, ')'));
		}
		else {
			DFS(ret, s + '(', lLeft - 1, rLeft);
			if (lLeft < rLeft) {
				DFS(ret, s + ')', lLeft, rLeft - 1);
			}
		}
	}
};