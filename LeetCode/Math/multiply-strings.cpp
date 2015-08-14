#include <string>
using std::string;
// Runtime: 8 ms
// https://leetcode.com/discuss/26602/brief-c-solution-using-only-strings-and-without-reversal
// Note: The numbers can be arbitrarily large and are non-negative.
class Solution {
public:
	string multiply(string num1, string num2) {
		string s(num1.size() + num2.size(), '0');
		for (int j = num2.size() - 1; j >= 0; j--) {
			if (num2[j] == '0') {
				continue;
			}
			int carry = 0;
			int nj = num2[j] - '0';
			for (int i = num1.size() - 1; i >= 0; i--) {
				int cur = s[i + j + 1] - '0' + nj * (num1[i] - '0') + carry;
				s[i + j + 1] = char(cur % 10 + '0');
				carry = cur / 10;
			}
			s[j] += carry;
		}
		size_t pos = s.find_first_not_of('0');
		if (pos == string::npos) {
			return "0";
		}
		else {
			return s.substr(pos);
		}


	}

	// Runtime: 68 ms
	// string multiply(string num1, string num2) {
	//     if (num1.size() < num2.size()) {
	//         return multiply(num2, num1);
	//     }
	//     string s = "";
	//     for (int j = 0; j < num2.size(); j++) {
	//         int carry = 0;
	//         string tmp = "";
	//         int nj = num2[j] - '0';
	//         if (nj == 0) {
	//             s += '0';
	//         } else if (nj == 1) {
	//             s += '0';
	//             s = addStr(s, num1);
	//         } else {
	//             for (int i = num1.size() - 1; i >= 0; i--) {
	//                 int cur = nj * (num1[i] - '0') + carry;
	//                 tmp = char(cur % 10 + '0') + tmp;
	//                 carry = cur / 10;
	//             }
	//             if (carry) {
	//                 tmp = char(carry + '0') + tmp;
	//             }
	//             if (j == 0) {
	//                 s = tmp;
	//             } else {
	//                 s += '0';
	//                 s = addStr(s, tmp);
	//             }
	//         }
	//     }
	//     // "0000"
	//     int pos0;
	//     for (pos0 = 0; pos0 < s.size(); pos0++) {
	//         if (s[pos0] != '0') {
	//             break;
	//         }
	//     }
	//     if (pos0 == s.size()) {
	//         return "0";
	//     } else {
	//         return s.substr(pos0);
	//     }
	// }
	// string addStr(const string& num1, const string& num2) {
	//     int i = num1.size() - 1, j = num2.size() - 1;
	//     int carry = 0;
	//     string s = "";
	//     while (i >= 0 || j >= 0 || carry) {
	//         int cur = (i >= 0 ? num1[i--] - '0' : 0) + (j >= 0 ? num2[j--] - '0' : 0) + carry;
	//         s = char(cur % 10 + '0') + s;
	//         carry = cur / 10;
	//     }
	//     return s;
	// }
};