#include <string>
#include <sstream>
#include <stack>
#include <vector>
using std::string;
using std::stringstream;
using std::stack;
using std::vector;

class Solution {
public:
	string simplifyPath(string path) { // Runtime: 8 ms
		stringstream ss(path);
		string sTmp, ret;
		vector<string> v;
		while (getline(ss, sTmp, '/')) {
			if (sTmp == "" || sTmp == ".") {
				continue;
			}
			else if (sTmp == "..") {
				if (!v.empty()) {
					v.pop_back();
				}
			}
			else {
				v.push_back(sTmp);
			}
		}
		for (auto str : v) {
			ret += "/" + str;
		}
		return ret.empty() ? "/" : ret;
	}

	string simplifyPath2(string path) { // Runtime: 12 ms
		for (auto& ch : path) {
			if (ch == '/') {
				ch = ' ';
			}
		}

		stringstream ss(path);
		stack<string> s;
		string str;
		while (ss >> str) {
			if (str.compare(".") == 0) {
				continue;
			}
			else if (str.compare("..") == 0) {
				if (!s.empty()) {
					s.pop();
				}
			}
			else {
				s.push(str);
			}
		}
		string sret("");
		while (!s.empty()) {
			sret = "/" + s.top() + sret;
			s.pop();
		}
		return sret.empty() ? "/" : sret;
		// 		if (sret.empty()) {
		// 			sret = "/";
		// 		}
		// 		return sret;
	}
};