#include <vector>
using std::vector;
// http://stackoverflow.com/questions/2680548/given-an-array-of-numbers-return-array-of-products-of-all-other-numbers-no-div
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) { // Runtime: 64 ms
		int size = nums.size();
		vector<int> product(size, 1);
		int p = 1;
		for (int i = 1; i < size; ++i) { // Runtime: 60 ms i++ --> ++i
			// product[i] = product[i - 1] * nums[i - 1];
			p = p * nums[i - 1];
			product[i] = p;
		}
		p = 1;
		for (int i = size - 2; i >= 0; --i) {
			p = p * nums[i + 1];
			product[i] *= p;
		}
		return product;
	}
};