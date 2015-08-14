#include <string>
#include <unordered_map>
using namespace std;
// Runtime: 4 ms
// Best: 0 ms done
// to_string
class Solution {
public:
	// -1, -2147483648
	// Input: 500, 10  
	string fractionToDecimal(int numerator, int denominator) {
		return fractionToDecimal2(numerator, denominator);
	}

	// optimized 0 ms
	string fractionToDecimal3(long long numerator, long long denominator) {
		bool positive = true;
		if (numerator < 0) {
			positive = !positive;
			numerator = -numerator;
		}
		if (denominator < 0) {
			positive = !positive;
			denominator = -denominator;
		}
		string s = positive ? "" : "-";
		if (numerator >= denominator) {
			// 			long long q = numerator / denominator;
			// 			while (q != 0) {
			// 				s = char(q % 10 + '0') + s;
			// 				q /= 10;
			// 			}
			s += to_string(numerator / denominator);
			numerator %= denominator;
			if (numerator == 0) {
				return s;
			}
			else {
				s = s + '.';
			}
		}
		else {
			if (numerator == 0) {
				return "0";
			}
			else {
				// 错误	1	error C2110: “+”: 不能添加两个指针	d:\qprograms\c\poj\poj\tmp.cpp	43	1	POJ
				// s = (positive ? "" : "-") + "0.";
				s += "0.";
			}
		}
		unordered_map<long long, int> m;
		int i = s.size();
		while (numerator != 0) {
			if (m.find(numerator) == m.end()) {
				m[numerator] = i;
				i++;
				long long quotient = numerator * 10 / denominator;
				numerator = numerator * 10 % denominator;
				s += char(quotient + '0');
			}
			else {
				return s.substr(0, m[numerator]) + '(' + s.substr(m[numerator]) + ')';
				// return s.insert(m[numerator], 1, '(') + ')';
			}
		}
		return s;

	}

	string fractionToDecimal2(long long numerator, long long denominator) {
		bool positive = true;
		if (numerator < 0) {
			positive = !positive;
			numerator = -numerator;
		}
		if (denominator < 0) {
			positive = !positive;
			denominator = -denominator;
		}
		string s = "";
		if (numerator >= denominator) {
			long long q = numerator / denominator;
			numerator %= denominator;
			while (q != 0) {
				s = char(q % 10 + '0') + s;
				q /= 10;
			}
			if (numerator == 0) {
				return (positive ? "" : "-") + s;
			}
			else {
				s = (positive ? "" : "-") + s + '.';
			}
		}
		else {
			if (numerator == 0) {
				return "0";
			}
			else {
				// 错误	1	error C2110: “+”: 不能添加两个指针	d:\qprograms\c\poj\poj\tmp.cpp	43	1	POJ
				// s = (positive ? "" : "-") + "0.";
				s = positive ? "0." : "-0.";
			}
		}
		int slen = s.size();
		unordered_map<long long, int> m;
		int i = 0;
		while (numerator != 0) {
			if (m.find(numerator) == m.end()) {
				m[numerator] = i;
				i++;
				long long quotient = numerator * 10 / denominator;
				numerator = numerator * 10 % denominator;
				s += char(quotient + '0');
			}
			else {
				return s.substr(0, slen + m[numerator]) + '(' + s.substr(slen + m[numerator]) + ')';
			}
		}
		return s;

	}
};