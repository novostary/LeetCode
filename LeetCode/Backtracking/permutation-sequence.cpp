#include <string>
#include <vector>
using std::string;
using std:: vector;
// 0 ms
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nums;
		for (int i = 0; i < n; i++) {
			nums.push_back(i);
		}

		string s;
		k--;
		int nfact = fact(n - 1);
		for (int i = n - 1; i > 0; i--) {
			s.push_back(nums[k / nfact] + '1');
			nums.erase(nums.begin() + k / nfact);
			k = k % nfact;
			nfact = nfact / i;
		}
		s.push_back(nums[0] + '1');
		return s;
	}
	int fact(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		else {
			return n * fact(n - 1);
		}
	}
};