struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 12 ms
// https://leetcode.com/discuss/8215/accepted-by-using-postorder-traversal iterator 
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) {
			return false;
		}
		sum = sum - root->val;
		if (!root->left && !root->right) {
			if (sum == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}
};