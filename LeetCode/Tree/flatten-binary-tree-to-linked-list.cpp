struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 8 ms
class Solution {
public:
	void flatten(TreeNode* root) {
		while (root) {
			if (root->left && root->right) {
				TreeNode* t = root->left;
				while (t->right) {
					t = t->right;
				}
				t->right = root->right;
			}
			if (root->left) {
				root->right = root->left;
			}
			root->left = nullptr;
			root = root->right;
		}
	}
	void flatten2(TreeNode* root) {
		while (root) {
			if (root->left) {
				TreeNode* t = root->left;
				while (t->right) {
					t = t->right;
				}
				t->right = root->right;
				root->right = root->left;
				root->left = nullptr;
			}
			root = root->right;
		}
	}
	void flatten3(TreeNode* root) {
		if (root) {
			flattenSub(root);
		}
	}
	TreeNode* flattenSub(TreeNode* root) {
		if (!root->left && !root->right) {
			return root;
		}
		else if (!root->left) {
			return flattenSub(root->right);
		}
		else if (!root->right) {
			root->right = root->left;
			root->left = nullptr;
			return flattenSub(root->right);
		}
		else {
			TreeNode* right = root->right;
			root->right = root->left;
			root->left = nullptr;
			TreeNode* node = flattenSub(root->right);
			node->right = right;
			return flattenSub(right);
		}
	}
};