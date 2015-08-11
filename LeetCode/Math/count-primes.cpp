#include <vector>
using std::vector;
// 28 ms
class Solution {
public:
	// int countPrimes(int n) { // 28 ms
	//     if (n <= 2) return 0;
	//     double c = sqrt(n);
	//     bool *bv = new bool[n];
	//     for(int i = 3; i <= c; i += 2)
	//         if (!bv[i]) 
	//             for(int j = i*i, k = i << 1; j < n; j += k)
	//                 bv[j] = 1;
	//     int num = 1;
	//     for(int i = 3; i < n; i += 2)
	//         if(!bv[i]) num++;
	//     return num;
	// }

	// int countPrimes(int n) {
	//     if (n < 3) {
	//         return 0;
	//     }
	//     // vector<bool> isPrime(n, true); // 212 ms
	//     vector<int> isPrime(n, 1);
	//     int upperbound = sqrt(n);
	//     for (int i = 3; i <= upperbound; i += 2) {
	//         if (isPrime[i]) {
	//             for (int j = i * i, k = i << 1; j < n; j += k) { // 56 ms
	//                 isPrime[j] = 0;
	//             }
	//         }
	//     }
	//     int count = 1;
	//     for (int i = 3; i < n; i += 2) {
	//         if (isPrime[i]) {
	//             count++;
	//         }
	//     }
	//     return count;
	// }

	int countPrimes(int n) {
		// 80 ms
		if (n < 3) {
			return 0;
		}
		vector<int> isPrime(n, 1);
		int count = 1;
		int upperbound = sqrt(n);
		for (int i = 3; i < n; i += 2) {
			if (isPrime[i]) {
				count++;
				if (i > upperbound) {
					continue;
				}
				for (int j = i * i, k = i << 1; j < n; j += k) { // 68 ms
					isPrime[j] = 0;
				}
			}
		}
		return count;
	}

	// int countPrimes(int n) {
	//     // 220 ms
	//     if (n < 3) {
	//         return 0;
	//     }
	//     vector<bool> isPrime(n, true);
	//     int count = 1;
	//     int upperbound = sqrt(n);
	//     for (int i = 3; i < n; i += 2) {
	//         if (isPrime[i]) {
	//             count++;
	//             if (i > upperbound) {
	//                 continue;
	//             }
	//             for (int j = i * i; j < n; j += i) {
	//                 isPrime[j] = false;
	//             }
	//         }
	//     }
	//     return count;
	// }

	// int countPrimes(int n) {
	//     vector<bool> isPrime(n, true);
	//     for (int i = 2; i * i < n; i++) {
	//         if (!isPrime[i]) {
	//             continue;
	//         }
	//         for (int j = i * i; j < n; j += i) {
	//             isPrime[j] = false;
	//         }
	//     }
	//     int count = 0;
	//     for (int i = 2; i < n; i++) {
	//         if (isPrime[i]) {
	//             count++;
	//         }
	//     }
	//     return count;
	// }
};