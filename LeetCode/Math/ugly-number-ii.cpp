#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
	// Runtime: 12 ms
	int nthUglyNumber(int n) {
		if (n < 1) {
			return 0;
		}
		vector<int> uglyNumbers(n, 1);
		auto p2 = uglyNumbers.begin(), p3 = uglyNumbers.begin(), p5 = uglyNumbers.begin();
		int nextUglyIndex = 1;
		int last = 1;
		int n2(2), n3(3), n5(5);
		while (nextUglyIndex < n) {
			if (n2 <= last) {
				n2 = *(++p2) * 2;
			}
			if (n3 <= last) {
				n3 = *(++p3) * 3;
			}
			if (n5 <= last) {
				n5 = *(++p5) * 5;
			}
			last = min(n2, min(n3, n5));
			uglyNumbers[nextUglyIndex++] = last;
		}
		return last;
	}
	// int nthUglyNumber(int n) {
	//     if (n < 1) {
	//         return 0;
	//     }
	//     int *pUglyNumbers = new int[n];
	//     pUglyNumbers[0] = 1;
	//     int *p2 = pUglyNumbers, *p3 = pUglyNumbers, *p5 = pUglyNumbers;
	//     int nextUglyIndex = 1;
	//     int last = 1;
	//     int n2(2), n3(3), n5(5);
	//     while (nextUglyIndex < n) {
	//         if (n2 <= last) {
	//             n2 = *(++p2) * 2;
	//         }
	//         if (n3 <= last) {
	//             n3 = *(++p3) * 3;
	//         }
	//         if (n5 <= last) {
	//             n5 = *(++p5) * 5;
	//         }
	//         last = min(n2, min(n3, n5));
	//         pUglyNumbers[nextUglyIndex++] = last;
	//     }
	//     delete []pUglyNumbers;
	//     return last;

	//     // while (nextUglyIndex < n) {
	//     //     int n2 = *p2 * 2, n3 = *p3 * 3, n5 = *p5 * 5;
	//     //     nextUglyNumber = min(n2, min(n3, n5));
	//     //     pUglyNumbers[nextUglyIndex++] = nextUglyNumber;
	//     //     if (n2 == nextUglyNumber) {
	//     //         ++p2;
	//     //     }
	//     //     if (n3 == nextUglyNumber) {
	//     //         ++p3;
	//     //     }
	//     //     if (n5 == nextUglyNumber) {
	//     //         ++p5;
	//     //     }
	//     // }

	//     // while (nextUglyIndex < n) {
	//     //     nextUglyNumber = min(*p2 * 2, min(*p3 * 3, *p5 * 5));
	//     //     pUglyNumbers[nextUglyIndex++] = nextUglyNumber;
	//     //     while (*p2 * 2 <= nextUglyNumber) { // only need to compare ==
	//     //         ++p2;
	//     //     }
	//     //     while (*p3 * 3 <= nextUglyNumber) {
	//     //         ++p3;
	//     //     }
	//     //     while (*p5 * 5 <= nextUglyNumber) {
	//     //         ++p5;
	//     //     }
	//     // }
	//     // delete []pUglyNumbers;
	//     // return nextUglyNumber;
	// }
};