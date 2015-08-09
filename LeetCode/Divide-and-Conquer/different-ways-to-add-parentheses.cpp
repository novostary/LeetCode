#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;
// Runtime: 4 ms
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> m;
		return diffWaysToCompute(input, m);
	}
	vector<int> diffWaysToCompute(string& input, unordered_map<string, vector<int>>& m) {
		vector<int> ret;
		if (input.empty()) {
			return ret;
		}
		if (m.find(input) != m.end()) {
			return m[input];
		}
		int size = input.size();
		for (int i = 0; i < size; i++) {
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*') {
				vector<int> ret1, ret2;
				string sub = input.substr(0, i);
				if (m.find(sub) != m.end()) {
					ret1 = m[sub];
				}
				else {
					ret1 = diffWaysToCompute(sub, m);
				}
				sub = input.substr(i + 1);
				if (m.find(sub) != m.end()) {
					ret2 = m[sub];
				}
				else {
					ret2 = diffWaysToCompute(sub, m);
				}
				merge(ret, ret1, ret2, cur);
			}
		}
		if (ret.empty()) {
			ret.push_back(atoi(input.c_str()));
		}
		m[input] = ret;
		return ret;
	}

	vector<int> diffWaysToCompute1(string input) {
		// Runtime: 8 ms
		vector<int> ret;
		if (input.empty()) {
			return ret;
		}
		int size = input.size();
		for (int i = 0; i < size; i++) {
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*') {
				vector<int> ret1 = diffWaysToCompute(input.substr(0, i));
				vector<int> ret2 = diffWaysToCompute(input.substr(i + 1));
				merge(ret, ret1, ret2, cur);
			}
		}
		if (ret.empty()) {
			ret.push_back(atoi(input.c_str()));
		}
		return ret;
	}

	vector<int> diffWaysToCompute2(string input) {
		vector<int> ret;
		if (input.empty()) {
			return ret;
		}
		vector<int> operands;
		vector<char> operators;
		init(operands, operators, input);
		// if (operators.empty()) {
		//     return operands;
		// }
		return diffWaysToCompute(operands, operators, 0, operators.size() - 1);

	}
	void init(vector<int>& operands, vector<char>& operators, const string& input) {
		int val = 0;
		for (auto ch : input) {
			if (ch == '+' || ch == '-' || ch == '*') {
				operators.push_back(ch);
				operands.push_back(val);
				val = 0;
			}
			else {
				val = val * 10 + ch - '0';
			}
		}
		operands.push_back(val);
	}
	vector<int> diffWaysToCompute(vector<int>& operands, vector<char>& operators, int left, int right) {
		vector<int> ret;
		// if (left == right) {
		//     ret.push_back(compute(operands[left], operands[left + 1], operators[left]));
		//     return ret;
		// } else 
		if (left > right) {
			ret.push_back(operands[left]);
			return ret;
		}
		vector<int> ret1, ret2, tmp;
		for (int mid = left; mid <= right; mid++) {
			ret1 = diffWaysToCompute(operands, operators, left, mid - 1);
			ret2 = diffWaysToCompute(operands, operators, mid + 1, right);
			merge(ret, ret1, ret2, operators[mid]);
		}
		return ret;
	}
	void merge(vector<int>& ret, vector<int>& ret1, vector<int>& ret2, char op) {
		for (auto i : ret1) {
			for (auto j : ret2) {
				ret.push_back(compute(i, j, op));
			}
		}
	}
	int compute(int operand1, int operand2, char op) {
		switch (op) {
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		default:
			break;
		}
	}
};