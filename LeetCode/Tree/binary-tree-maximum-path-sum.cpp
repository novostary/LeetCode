#include <limits>
#include <algorithm>
using std::max;
// Runtime: 32 ms
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		int ret = INT_MIN;
		maxToRoot(root, ret);
		return ret;
	}
	int maxToRoot(TreeNode* root, int& ret) {
		if (!root) {
			return 0;
		}
		int left = max(0, maxToRoot(root->left, ret));
		int right = max(0, maxToRoot(root->right, ret));
		ret = max(ret, left + right + root->val);
		return root->val + max(left, right);
	}
};