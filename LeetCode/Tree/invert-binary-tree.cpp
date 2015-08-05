struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 0 ms
// https://leetcode.com/discuss/40001/straightforward-dfs-recursive-iterative-bfs-solutions
// Heap, Stack
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) {
			return root;
		}
		TreeNode* tmp = root->right;
		root->right = invertTree(root->left);
		root->left = invertTree(tmp);
		return root;
	}
};