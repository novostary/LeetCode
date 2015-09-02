#include <vector>
#include <algorithm>
using std::vector;
using std::swap;
// https://leetcode.com/discuss/54454/swapping-numbers-to-the-same-index-cell
class Solution {
public:
	int missingNumber1(vector<int>& nums) { // Runtime: 36 ms
		int size = nums.size();
		long long missing = ((long long)size * (size + 1)) >> 1;
		for (auto num : nums) {
			missing -= num;
		}
		return missing;
	}

	int missingNumber(vector<int>& nums) { // Runtime: 36 ms
		int size = nums.size();
		int ret = size;
		for (int i = 0; i < size; i++) {
			ret ^= nums[i] ^ i;
		}
		return ret;
	}

	int missingNumber2(vector<int>& nums) { // Runtime: 36 ms
		int cur = 0, pre = -1, size = nums.size();
		while (cur < size) {
			if (nums[cur] != cur) {
				if (nums[cur] != size) {
					swap(nums[cur], nums[nums[cur]]);
				}
				else {
					pre = cur;
					cur++;
				}
			}
			else {
				cur++;
			}
		}
		return pre == -1 ? size : pre;
	}
};