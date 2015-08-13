#include <vector>
using std::vector;
// Runtime: 20 ms
// Boyer-Moore Majority Vote algorithm 
// http://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
// https://leetcode.com/discuss/43248/boyer-moore-majority-vote-algorithm-and-my-elaboration
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> ret;
		int n1 = 0, n2 = 1, count1 = 0, count2 = 0;
		for (auto n : nums) {
			if (n == n1) {
				count1++;
			}
			else if (n == n2) {
				count2++;
			}
			else if (count1 == 0) {
				n1 = n;
				count1 = 1;
			}
			else if (count2 == 0) {
				n2 = n;
				count2 = 1;
			}
			else {
				count1--;
				count2--;
			}
		}
		if (count1 != 0 && validateME(nums, n1)) {
			ret.push_back(n1);
		}
		if (count2 != 0 && validateME(nums, n2)) {
			ret.push_back(n2);
		}
		return ret;
	}
	bool validateME(vector<int>& nums, int val) {
		int count = 0;
		for (auto n : nums) {
			if (n == val) {
				count++;
			}
		}
		if (count > nums.size() / 3) {
			return true;
		}
		else {
			return false;
		}
	}
};