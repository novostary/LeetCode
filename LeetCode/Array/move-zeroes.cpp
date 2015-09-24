#include <vector>
using std::vector;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int size = nums.size();
		int i = 0, j = 0;
		while (i < size && nums[i] != 0) {
			++i;
		}
		for (j = i + 1; j < size; ++j) {
			if (nums[j] != 0) {
				nums[i] = nums[j];
				++i;
			}
		}
		while (i < size) {
			nums[i++] = 0;
		}
	}
};