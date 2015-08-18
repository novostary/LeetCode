#include <vector>
#include <algorithm>
using std::vector;
using std::swap;
// Runtime: 4 ms
// Dutch national flag problem by Edsger Dijkstra
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i = 0, j = 0, k = nums.size() - 1;
		while (j <= k) {
			if (nums[j] == 0) {
				swap(nums[i++], nums[j++]);
			}
			else if (nums[j] == 1) {
				j++;
			}
			else {
				swap(nums[j], nums[k--]);
			}
		}
	}

	void sortColors2(vector<int>& nums) {
		int num0 = 0, num1 = 0, num2 = 0;
		for (auto n : nums) {
			if (n == 0) {
				num0++;
			}
			else if (n == 1) {
				num1++;
			}
			else {
				num2++;
			}
		}
		for (int j = 0; j < num0; j++) {
			nums[j] = 0;
		}
		for (int j = 0; j < num1; j++) {
			nums[num0 + j] = 1;
		}
		for (int j = 0; j < num2; j++) {
			nums[num0 + num1 + j] = 2;
		}
	}
};