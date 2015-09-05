#include <string>
#include <stack>
using std::string;
using std::stack;
// https://leetcode.com/discuss/39553/iterative-java-solution-with-stack
class Solution {
public:
	int calculate(string s) { // Runtime: 16 ms
		stack<int> st;
		int result = 0;
		int number = 0;
		int sign = 1;
		for (int i = 0; i < s.size(); ++i) {
			char c = s.at(i);
			if (isdigit(c)) {
				number = 10 * number + c - '0';
			}
			else if (c == '+') {
				result += sign * number;
				number = 0;
				sign = 1;
			}
			else if (c == '-') {
				result += sign * number;
				number = 0;
				sign = -1;
			}
			else if (c == '(') {
				st.push(result);
				st.push(sign);
				sign = 1;
				result = 0;
			}
			else if (c == ')') {
				result += sign * number;
				number = 0;
				result *= st.top();
				st.pop();
				result += st.top();
				st.pop();
			}
		}
		if (number != 0) {
			result += sign * number;
		}
		return result;
	}
};