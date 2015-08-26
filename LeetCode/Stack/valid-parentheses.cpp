#include <string>
#include <stack>
using std::string;
using std::stack;
// We can also use if-else, or use a map to match brackets.
class Solution { // Runtime: 0 ms
public:
	bool isValid(string s) {
		stack<char> st;
		for (auto ch : s) {
			switch (ch) {
			case '(':
				st.push(')');
				break;
			case '{':
				st.push('}');
				break;
			case '[':
				st.push(']');
				break;
			case ')':
			case '}':
			case ']':
				if (st.empty() || ch != st.top()) {
					return false;
				}
				st.pop();
				break;
			default:
				return false;
			}
		}
		return st.empty();
	}
};