#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (m > n) {
			return findMedianSortedArrays(nums2, nums1);
		}

		int ileft = 0, iright = m;
		int i, j, n1, n2;
		int target = (m + n + 1) >> 1;

		while (ileft <= iright) {
			i = (ileft + iright) >> 1;
			j = target - i;
			if (i < m && j > 0 && nums1[i] < nums2[j - 1]) {
				ileft = i + 1;
			}
			else if (i > 0 && j < n && nums1[i - 1] > nums2[j]) {
				iright = i - 1;
			}
			else {
				break;
			}
		}

		if (i == 0) {
			n1 = nums2[j - 1];
		}
		else if (j == 0) {
			n1 = nums1[i - 1];
		}
		else {
			n1 = max(nums1[i - 1], nums2[j - 1]);
		}
		if ((m + n) & 1) {
			return n1;
		}
		else {
			if (i == m) {
				n2 = nums2[j];
			}
			else if (j == n) {
				n2 = nums1[i];
			}
			else {
				n2 = min(nums1[i], nums2[j]);
			}
			return (n1 + n2) / 2.0;
		}
	}
};