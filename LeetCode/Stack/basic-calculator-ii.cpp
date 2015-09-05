#include <string>
#include <vector>
#include <sstream>
using std::string;
using std::vector;
using std::istringstream;
// https://leetcode.com/discuss/41902/share-my-java-solution
// https://leetcode.com/discuss/42643/my-16-ms-no-stack-one-pass-short-c-solution
class Solution {
public:
	int calculate(string s) { // Runtime: 20 ms
		int len = s.size();
		if (len == 0) {
			return 0;
		}
		vector<int> st;
		int number = 0;
		char sign = '+';
		for (int i = 0; i < len; ++i) {
			char ch = s.at(i);
			if (isdigit(ch)) {
				number = number * 10 + ch - '0';
			}
			if (!isdigit(ch) && ch != ' ' || i == len - 1) {
				if (sign == '+') {
					st.push_back(number);
				}
				else if (sign == '-') {
					st.push_back(-number);
				}
				else if (sign == '*') {
					int temp = st.back();
					st.pop_back();
					st.push_back(temp * number);
				}
				else if (sign == '/') {
					int temp = st.back();
					st.pop_back();
					st.push_back(temp / number);
				}
				sign = ch;
				number = 0;
			}
		}
		int result = 0;
		for (auto i : st) {
			result += i;
		}
		return result;
	}

	int calculate2(string s) { // Runtime: 20 ms
		istringstream in('+' + s + '+');
		int total = 0, term = 0, n;
		char op;
		while (in >> op) {
			if (op == '+' || op == '-') {
				total += term;
				in >> term;
				term *= 44 - op;
				// term *= (op == '+' ? 1 : -1);
			}
			else {
				in >> n;
				if (op == '*') {
					term *= n;
				}
				else {
					term /= n;
				}
			}
		}
		return total;
	}

	int calculate3(string s) { // Runtime: 16 ms
		int result = 0, cur_res = 0;
		char op = '+';
		for (int pos = s.find_first_not_of(' '); pos < s.size(); pos = s.find_first_not_of(' ', pos)) {
			char ch = s[pos];
			if (isdigit(ch)) {
				int tmp = ch - '0';
				while (++pos < s.size() && isdigit(s[pos])) {
					tmp = tmp * 10 + s[pos] - '0';
				}
				switch (op) {
				case '+':
					cur_res += tmp;
					break;
				case '-':
					cur_res -= tmp;
					break;
				case '*':
					cur_res *= tmp;
					break;
				case '/':
					cur_res /= tmp;
					break;
				}
			}
			else {
				if (ch == '+' || ch == '-') {
					result += cur_res;
					cur_res = 0;
				}
				op = ch;
				++pos;
				// op = s[pos++];
			}
		}
		return result + cur_res;
	}
};