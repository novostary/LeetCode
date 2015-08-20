#include <string>
using std::string;

class Solution {
public:
	// Runtime: 16 ms
	string convert(string s, int numRows) {
		if (numRows <= 1) {
			return s;
		}
		string res = "";
		int size = s.size();
		for (int i = 0; i < numRows; i++) {
			if (i == 0 || i == numRows - 1) {
				for (int j = i; j < size; j += (numRows - 1) * 2) {
					res += s.at(j);
				}
			}
			else {
				for (int j = i; j < size; j += (numRows - 1) * 2) {
					res += s.at(j);
					if ((numRows - 1) * 2 - 2 * i + j < size) {
						res += s.at((numRows - 1) * 2 - 2 * i + j);
					}
				}
			}
		}
		return res;
	}

	// Runtime: 28 ms
	// string convert(string s, int numRows) {
	//     if (numRows <= 1) {
	//         return s;
	//     }
	//     vector<string> ret(numRows, "");
	//     int i = 0, size = s.size();
	//     while (i < size) {
	//         for (int j = 0; j < numRows && i < size; j++) {
	//             ret[j] += s.at(i++);
	//         }
	//         for (int j = numRows - 2; j > 0 && i < size; j--) {
	//             // ret[j] += s[i++];
	//             ret[j] += s.at(i++);
	//         }
	//     }
	//     string res = "";
	//     for (auto sr : ret) {
	//         res += sr;
	//     }
	//     return res;
	// }


	// Runtime: 228 ms
	// string convert(string s, int numRows) {
	//     if (numRows <= 1) {
	//         return s;
	//     } 
	//     int mod = (numRows - 1) * 2;
	//     string res = "";
	//     for (int i = 0; i < numRows; i++) {
	//         for (int j = 0; j < s.size(); j++) {
	//             if (j % mod == i || j % mod == mod - i) {
	//                 res += s[j];
	//             }
	//         }
	//     }
	//     return res;
	// }
};