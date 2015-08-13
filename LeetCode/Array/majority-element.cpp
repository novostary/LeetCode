#include <vector>
#include <cstdlib>
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

	int majorityElement2(vector<int>& nums) {
		int size = nums.size();
		while (true) {
			int r = nums[rand() % size];
			int count = 0;
			for (int i = 0; i < size; i++) {
				if (r == nums[i]) {
					count++;
				}
			}
			if (count > size >> 1) {
				return r;
			}
		}
	}
};