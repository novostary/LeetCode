#include <vector>
#include <algorithm>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
	// Runtime: 36 ms
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums[i - 1] == nums[i]) {
				return true;
			}
		}
		return false;
	}

	// Runtime: 48 ms
	 bool containsDuplicate2(vector<int>& nums) {
	     unordered_set<int> set;
	     for (auto n : nums) {
	         if (set.find(n) == set.end()) {
	             set.insert(n);
	         } else {
	             return true;
	         }
	     }
	     return false;
	 }
};