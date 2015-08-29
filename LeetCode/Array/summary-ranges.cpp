#include <string>
#include <vector>
using std::string;
using std::vector;
using std::to_string;
// Runtime: 0 ms
// https://leetcode.com/discuss/42229/10-line-c-easy-understand
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ret;
		if (nums.empty()) {
			return ret;
		}
		int first = 0, end = 0;
		int size = nums.size();
		while (first < size) {
			while (end + 1 < size && nums[end + 1] == nums[end] + 1) {
				end++;
			}
			if (first == end) {
				ret.push_back(to_string(nums[first]));
			}
			else {
				ret.push_back(to_string(nums[first]) + "->" + to_string(nums[end]));
			}
			first = end + 1;
			end = first;
		}
		return ret;
	}

	vector<string> summaryRanges1(vector<int>& nums) {
		vector<string> ret;
		if (nums.empty()) {
			return ret;
		}
		int first = 0, last = 0;
		int size = nums.size();
		for (int i = 1; i < size; i++) {
			if (nums[i - 1] + 1 != nums[i]) {
				last = i - 1;
				if (first == last) {
					ret.push_back(to_string(nums[first]));
				}
				else {
					ret.push_back(to_string(nums[first]) + "->" + to_string(nums[last]));
				}
				first = i;
				last = i;
			}
		}
		last = size - 1;
		if (first == last) {
			ret.push_back(to_string(nums[first]));
		}
		else {
			ret.push_back(to_string(nums[first]) + "->" + to_string(nums[last]));
		}
		return ret;
	}
};