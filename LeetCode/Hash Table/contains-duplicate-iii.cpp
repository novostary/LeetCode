#include <algorithm>
#include <vector>
#include <set>
using std::vector;
using std::sort;
using std::set;
// https://leetcode.com/discuss/38206/ac-o-n-solution-in-java-using-buckets-with-explanation bucket...
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) { // Runtime: 16 ms
		const int N = nums.size();
		// int* numptrs[N];
		int** numptrs;
		// numptrs = (int**)malloc(sizeof(int*)* N);
		// numptrs = new (int*)[N]; // error
		numptrs = new int*[N];

		for (int i = 0; i < N; ++i) {
			numptrs[i] = &nums[i];
		}
		sort(numptrs, numptrs + N, cmpptr);
		// if (0 == k) {
		//     return false;
		// }
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (*numptrs[j] > *numptrs[i] + t) {
					break;
				}
				if (abs(numptrs[j] - numptrs[i]) <= k) {
					return true;
				}
			}
		}
		return false;
	}

	 bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) { // Runtime: 16 ms
	     const int N = nums.size();
	     vector<int*> numptrs(N);
	     for (int i = 0; i < N; ++i) {
	         numptrs[i] = &nums[i];
	     }
	     sort(numptrs.begin(), numptrs.end(), cmpptr);
	     if (0 == k) {
	         return false;
	     }
	     for (int i = 0; i < N; ++i) {
	         for (int j = i + 1; j < N; ++j) {
	             if (*numptrs[j] > *numptrs[i] + t) {
	                 break;
	             }
	             if (abs(numptrs[j] - numptrs[i]) <= k) {
	                 return true;
	             }
	         }
	     }
	     return false;
	 }
	static bool cmpptr(const int *a, const int *b) {
		return *a < *b;
	}

	 bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) { // Runtime: 48 ms
	     set<int> window;
	     for (int i = 0; i < nums.size(); ++i) {
	         if ( i > k) {
	             window.erase(nums[i - k - 1]);
	         }
	         auto pos = window.lower_bound(nums[i] - t);
	         if (pos != window.end() && *pos - nums[i] <= t) {
	             return true;
	         }
	         window.insert(nums[i]);
	     }
	     return false;
	 }

	 bool containsNearbyAlmostDuplicate3(vector<int>& nums, int k, int t) { // Time Limit Exceeded
	     for (int i = 0; i < nums.size(); ++i) {
	         for (int j = i + 1; j <= i + k && j < nums.size(); ++j) {
	             if (abs(nums[i] - nums[j]) <= t) {
	                 return true;
	             }
	         }
	     }
	     return false;
	 }
};