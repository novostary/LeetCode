#include <string>
#include <vector>
#include <stack>
using std::string;
using std::vector;
using std::stack;
// https://en.wikipedia.org/wiki/Reverse_Polish_notation
// https://leetcode.com/discuss/4076/6-%EF%BC%88-132%EF%BC%89-0-or-1
// https://leetcode.com/discuss/17937/accepted-recursive-solution-explanation-simplest-possible
// https://en.wikipedia.org/wiki/Shunting-yard_algorithm
class Solution {
public:
	int evalRPN(vector<string>& tokens) { // Runtime: 16 ms
		stack<int> stk;
		for (auto token : tokens) {
			if (isOp(token)) {
				cal(stk, token);
			}
			else {
				stk.push(atoi(token.c_str()));
			}
		}
		
		return stk.size() == 1 ? stk.top() : 0;
	}
private:
	bool isOp(string op) {
		return op == "+" || op == "-" || op == "*" || op == "/";
	}
	void cal(stack<int>& stk, string op) {
		int opr2 = stk.top();
		stk.pop();
		int opr1 = stk.top();
		stk.pop();
		if (op == "+") {
			opr1 += opr2;
		}
		else if (op == "-") {
			opr1 -= opr2;
		}
		else if (op == "*") {
			opr1 *= opr2;
		}
		else if (op == "/") {
			opr1 /= opr2;
		}
		stk.push(opr1);
	}
};