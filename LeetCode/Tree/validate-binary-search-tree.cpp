struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 12 ms
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, nullptr, nullptr);
	}
	bool isValidBST(TreeNode* root, int *lowerBound, int *upperBound) {
		if (!root) {
			return true;
		}
		if (lowerBound && upperBound) {
			if (!(root->val > *lowerBound && root->val < *upperBound)) {
				return false;
			}
		}
		else if (lowerBound) {
			if (root->val <= *lowerBound) {
				return false;
			}
		}
		else if (upperBound) {
			if (root->val >= *upperBound) {
				return false;
			}
		}
		return isValidBST(root->left, lowerBound, &(root->val)) && isValidBST(root->right, &(root->val), upperBound);
	}

	bool isValidBST2(TreeNode* root) {
		TreeNode* prev = nullptr;
		return isValidBST(root, prev);
	}
	bool isValidBST(TreeNode* node, TreeNode* &prev) {
		if (!node) {
			return true;
		}
		if (!isValidBST(node->left, prev)) {
			return false;
		}
		if (prev && prev->val >= node->val) {
			return false;
		}
		prev = node;
		return isValidBST(node->right, prev);
	}
};
