#include <vector>
using std::vector;
// Runtime: 16 ms
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int maj = nums[0], count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (count == 0) {
				maj = nums[i];
				count++;
			}
			else if (maj == nums[i]) {
				count++;
			}
			else {
				count--;
			}
		}
		return maj;
	}
};