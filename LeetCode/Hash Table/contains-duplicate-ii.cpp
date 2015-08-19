#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// https://leetcode.com/discuss/40733/20-ms-c-solution-with-stl
// https://leetcode.com/discuss/37851/c-solution-with-unordered_set
class Solution {
public:
	// Runtime: 28 ms
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (k <= 0) {
			return false;
		}
		unordered_set<int> s;
		for (int i = 0; i < nums.size(); i++) {
			if (k < i) {
				s.erase(nums[i - k - 1]);
			}
			if (s.find(nums[i]) != s.end()) {
				return true;
			}
			else {
				s.insert(nums[i]);
			}
		}
		return false;
	}

	// Runtime: 32 ms
	bool containsNearbyDuplicate1(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (m.find(nums[i]) == m.end()) {
				m[nums[i]] = i;
			}
			else {
				if (i - m[nums[i]] <= k) {
					return true;
				}
				else {
					m[nums[i]] = i;
				}
			}
		}
		return false;
	}

	// Runtime: 32 ms
	 bool containsNearbyDuplicate2(vector<int>& nums, int k) {
	     unordered_map<int, size_t> m;
	     size_t len = nums.size();
	     size_t szk = (size_t)k; // 36
	     for (size_t i = 0; i < len; i++) {
	         if (m.find(nums[i]) == m.end()) {
	             m[nums[i]] = i;
	         } else {
	             if (i - m[nums[i]] <= szk) {
	                 return true;
	             } else {
	                 m[nums[i]] = i;
	             }
	         }
	     }
	     return false;
	 }

	 // [0,...,29999], 29999
	 // Time Limit Exceeded
	 bool containsNearbyDuplicate3(vector<int>& nums, int k) {
		 if (k <= 0) {
			 return false;
		 }
		 for (auto iter1 = nums.begin(); iter1 != nums.end(); iter1++) {
			 if (nums.end() - iter1 > k) {
				 auto iter2 = find(iter1 + 1, iter1 + k + 1, *iter1);
				 if (iter2 != iter1 + k + 1) {
					 return true;
				 }
			 }
			 else {
				 auto iter2 = find(iter1 + 1, nums.end(), *iter1);
				 if (iter2 != nums.end()) {
					 return true;
				 }
			 }
		 }
		 return false;
	 }
};