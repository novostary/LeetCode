#include <vector>
#include <string>
using std::vector;
using std::string;
// Runtime: 0 ms
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		if (s.empty()) {
			return ret;
		}
		bt(ret, s, "", 0, 0);
		return ret;
	}
	void bt(vector<string>& ret, string s, string curr, int index, int count) {
		if (count == 4) {
			if (index == s.size()) {
				curr.erase(curr.end() - 1);
				ret.push_back(curr);
			}
			return;
		}
		if (s.size() - index > (4 - count) * 3 || s.size() - index < 4 - count) {
			return;
		}
		/*if (s[index] == '0') {
		// curr = count < 3 ? curr + "0." : curr + '0';
		// bt(ret, s, curr, index + 1, count + 1);
		bt(ret, s, curr + "0.", index + 1, count + 1);
		return;
		}*/
		int num = 0;
		for (int i = 0; i < 3 && index + i < s.size(); i++) {
			num = num * 10 + s[index + i] - '0';
			if (num < 256) {
				// curr = count < 3 ? curr + s.substr(index, i + 1) + '.' : curr + s.substr(index, i + 1);
				// bt(ret, s, curr, index + i + 1, count + 1);
				// bt(ret, s, count < 3 ? curr + s.substr(index, i + 1) + '.' : curr + s.substr(index, i + 1), index + i + 1, count + 1);
				// bt(ret, s, curr + s.substr(index, i + 1) + '.', index + i + 1, count + 1);
				curr += s[index + i];
				bt(ret, s, curr + '.', index + i + 1, count + 1);
			}
			if (num == 0) {
				break;
			}
		}
	}
};