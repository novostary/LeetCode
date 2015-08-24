#include <vector>
#include <queue>
#include <set>
using std::vector;
using std::priority_queue;
using std::multiset;
// https://leetcode.com/discuss/38336/solutions-partition-priority_queue-multiset-respectively 复杂度分析，主定理
// <Introduction to Algorithms>
// https://leetcode.com/discuss/36966/solution-explained Random
// priority_queue, Priority queues are a type of container adaptors, 
// specifically designed such that its first element is always the greatest of the elements it contains, 
// according to some strict weak ordering criterion.
// Multisets are containers that store elements following a specific order, and where multiple elements can have equivalent values.
class Solution {
public:
	// Runtime: 4 ms
	int findKthLargest(vector<int>& nums, int k) {
		if (k < 1 || k > nums.size()) {
			return 0;
		}
		int i = 0, j = nums.size() - 1;
		while (true) {
			int pos = partition(nums, i, j);
			if (pos == -1) {
				return 0;
			}
			if (pos + 1 == k) {
				return nums[pos];
			}
			else if (pos + 1 > k) {
				j = pos - 1;
			}
			else {
				i = pos + 1;
				//k = k - (pos + 1);
			}
		}
	}
	int partition(vector<int>& nums, int i, int j) {
		if (i > j) {
			return -1;
		}
		int target = nums[i];
		int l = i, r = j;
		while (l < r) {
			while (l < r && nums[r] < target) {
				r--;
			}
			if (l < r) {
				nums[l] = nums[r];
				l++;
			}
			while (l < r && nums[l] >= target) {
				l++;
			}
			if (l < r) {
				nums[r] = nums[l];
				r--;
			}
		}
		nums[l] = target;
		return l;
	}

	// Runtime: 8 ms
	int findKthLargest2(vector<int>& nums, int k) {
		priority_queue<int> pq(nums.begin(), nums.end());
		for (int i = 0; i < k - 1; i++) {
			pq.pop();
		}
		return pq.top();
	}

	// Runtime: 12 ms, same as sort
	int findKthLargest3(vector<int>& nums, int k) {
		multiset<int> mset;
		for (auto num : nums) {
			mset.insert(num);
			if (mset.size() > k) {
				mset.erase(mset.begin());
			}
		}
		return *mset.begin();
	}
};