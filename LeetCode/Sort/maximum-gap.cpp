#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;
// Runtime: 8 ms
// bucket sort
// https://leetcode.com/discuss/18499/bucket-sort-java-solution-with-explanation-o-time-and-space
// https://leetcode.com/discuss/27754/my-c-code-12-ms-bucket-sort-o-n-time-and-space
class Solution {
public:
	// Runtime: 8 ms
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) {
			return 0;
		}

		int minV = nums[0], maxV = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			//minV = min(minV, nums[i]); // Runtime: 12 ms
			//maxV = max(maxV, nums[i]);
			if (minV > nums[i]) { // Runtime: 8 ms
				minV = min(minV, nums[i]);
			}
			else {
				maxV = max(maxV, nums[i]);
			}
		}

		int bucketSize = max(1, (maxV - minV) / ((int)nums.size() - 1));
		int bucketNum = (maxV - minV) / bucketSize + 1;
		if (bucketNum == 1) {
			return maxV - minV;
		}

		vector<int> bucketMax(bucketNum, INT_MIN);
		vector<int> bucketMin(bucketNum, INT_MAX);
		vector<int> bucketCount(bucketNum, 0);

		for (auto n : nums) {
			int index = (n - minV) / bucketSize;
			bucketCount[index]++;
			bucketMax[index] = max(bucketMax[index], n);
			bucketMin[index] = min(bucketMin[index], n);
		}

		int preMax = minV;
		int maxGap = INT_MIN;
		for (int i = 0; i < bucketNum; i++) {
			if (bucketCount[i] > 0) {
			// if (bucketMin[i] != INT_MAX || bucketMax[i] != INT_MIN) // don't use bucketCount
				maxGap = max(maxGap, bucketMin[i] - preMax);
				preMax = bucketMax[i];
			}
		}
		return maxGap;
	}

	// Runtime: 16 ms
	int maximumGap3(vector<int>& nums) {
		if (nums.size() < 2) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		int maxGap = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			maxGap = max(nums[i + 1] - nums[i], maxGap);
		}
		return maxGap;
	}
};