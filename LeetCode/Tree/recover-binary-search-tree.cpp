struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 48 ms
// https://leetcode.com/discuss/13034/no-fancy-algorithm-just-simple-and-powerful-order-traversal
class Solution {
public:
	void recoverTree(TreeNode* root) {
		TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
		find(root, prev, first, second);
		if (first) {
			int temp = first->val;
			first->val = second->val;
			second->val = temp;
		}
	}
	void find(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
		if (!root) {
			return;
		}
		find(root->left, prev, first, second);
		if (prev && prev->val > root->val) {
			if (!first) {
				first = prev;
				second = root;
			}
			else {
				second = root;
				return;
			}
		}
		prev = root;
		find(root->right, prev, first, second);
	}
};
