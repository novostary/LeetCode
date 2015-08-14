#include <algorithm>
using std::max;
using std::min;
// Runtime: 32 ms
class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int x1 = max(A, E), y1 = max(B, F), x2 = min(C, G), y2 = min(D, H);
		int area = (D - B) * (C - A) + (H - F) * (G - E);
		if (x1 >= x2 || y1 >= y2) {
			return area;
		}
		else {
			return area - (y2 - y1) * (x2 - x1);
		}
	}

	int computeArea2(int A, int B, int C, int D, int E, int F, int G, int H) {
		int left = max(A, E), right = max(min(C, G), left);
		int bottom = max(B, F), top = max(min(D, H), bottom);
		return (C - A)*(D - B) - (right - left)*(top - bottom) + (G - E)*(H - F);
	}
};