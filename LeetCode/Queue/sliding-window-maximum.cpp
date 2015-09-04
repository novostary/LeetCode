#include <vector>
#include <deque>
#include <set>
#include <utility>
#include <queue>
using std::vector;
using std::deque;
using std::multiset;
using std::priority_queue;
using std::pair;
using std::make_pair;
// Monotonic Queue
// http://abitofcs.blogspot.com/2014/11/data-structure-sliding-window-minimum.html
// https://leetcode.com/discuss/46594/clean-c-o-n-solution-using-a-deque
// https://leetcode.com/discuss/46649/3-c-solutions multiset, priority_queue, deque
// https://leetcode.com/discuss/48825/accepted-104ms-c-solution-with-maxqueue max queue
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) { // Runtime: 96 ms
		deque<int> dq;
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			if (!dq.empty() && dq.front() == i - k) {
				dq.pop_front();
			}
			while (!dq.empty() && nums[dq.back()] < nums[i]) {
				dq.pop_back();
			}
			dq.push_back(i);
			if (i >= k - 1) {
				ans.push_back(nums[dq.front()]);
			}
		}
		return ans;
	}

	vector<int> maxSlidingWindow2(vector<int>& nums, int k) { // 152 ms
		vector<int> ans;
		multiset<int> ms;
		for (int i = 0; i < nums.size(); ++i) {
			if (i >= k) {
				ms.erase(ms.find(nums[i - k]));
			}
			ms.insert(nums[i]);
			if (i >= k - 1) {
				ans.push_back(*ms.rbegin());
			}
		}
		return ans;
	}

	vector<int> maxSlidingWindow3(vector<int>& nums, int k) { // Runtime: 120 ms
		vector<int> ans;
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < nums.size(); ++i) {
			while (!pq.empty() && pq.top().second <= i - k) {
				pq.pop();
			}
			pq.push(make_pair(nums[i], i));
			if (i >= k - 1) {
				ans.push_back(pq.top().first);
			}
		}
		return ans;
	}
};