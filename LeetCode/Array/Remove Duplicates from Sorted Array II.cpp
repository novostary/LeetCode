#include <iostream>
#include <vector>
using std::vector;
// Runtime: 20 ms
// 16ms??  return ++len;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		/*if (nums.empty()) {
			return 0;
		}
		else {
			int len = 0;
			bool isFirst = true;
			for (int i = 1; i < nums.size(); i++) {
				if (nums[len] != nums[i]) {
					nums[++len] = nums[i];
					isFirst = true;
				}
				else if (isFirst){
					isFirst = false;
					nums[++len] = nums[i];
				}
			}
			return len + 1;
		}*/
		int i = 0;
		for (int n : nums)
		if (i < 2 || n > nums[i - 2])
			nums[i++] = n;
		return i;
	}
};