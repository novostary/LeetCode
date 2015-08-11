#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;
// 8ms?
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// Runtime: 36 ms
		// unordered_map Runtime: 24 ms
		vector<int> res;
		map<int, int> numsMap;
		for (int i = 0; i < nums.size(); i++) {
			numsMap[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (numsMap.find(target - nums[i]) != numsMap.end()) {
				int index = numsMap[target - nums[i]];
				if (index != i) {
					if (index < i) {
						res.push_back(index + 1);
						res.push_back(i + 1);
						break;
					}
					else {
						res.push_back(i + 1);
						res.push_back(index + 1);
						break;
					}
				}
			}
		}
		return res;
	}

	// Runtime: 16 ms
	/* unordered_map<int, int> map;
	int n = (int)nums.size();
	for (int i = 0; i < n; i++) {
	auto p = map.find(target-nums[i]);
	if (p!=map.end()) {
	return {p->second+1, i+1};
	}
	map[nums[i]]=i;
	} */
};