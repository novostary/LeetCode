#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> res(digits);
		int carry = 0;
		for (int i = res.size() - 1; i >= 0; i--) {
			res[i]++;
			if (res[i] >= 10) {
				res[i] = 0;
				carry = 1;
			}
			else {
				carry = 0;
				break;
			}
		}
		if (carry == 1) {
			res.insert(res.begin(), 1);
		}
		return res;
	}
};