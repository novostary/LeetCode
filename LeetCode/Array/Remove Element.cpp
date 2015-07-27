#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = 0;
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] != val) {
				nums[len++] = nums[j];
			} 
		}
		return len;
	}
};

//int main()
//{
//	return 0;
//}