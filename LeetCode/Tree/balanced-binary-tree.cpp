#include <algorithm>
using std::abs;
using std::max;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 12 ms

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (balancedHeight(root) == -1) {
			return false;
		}
		else {
			return true;
		}
	}
	int balancedHeight(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int left = balancedHeight(root->left);
		if (left == -1) {
			return -1;
		}
		int right = balancedHeight(root->right);
		if (right == -1) {
			return -1;
		}
		if (abs(left - right) <= 1) {
			return 1 + max(left, right);
		}
		else {
			return -1;
		}
	}
};