struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 4 ms
class Solution {
public:
	int sumNumbers(TreeNode* root, int b = 0) {
		if (!root) {
			return 0;
		}
		b = 10 * b + root->val;
		if (root->left || root->right) {
			return sumNumbers(root->left, b) + sumNumbers(root->right, b);
		}
		else {
			return b;
		}
	}
	// int sumNumbers(TreeNode* root) {
	//     int sum = 0;
	//     sumNumbers(root, 0, sum);
	//     return sum;
	// }
	// void sumNumbers(TreeNode* node, int cur, int& sum) {
	//     if (!node) {
	//         return;
	//     }
	//     cur = cur * 10 + node->val;
	//     if (!node->left && !node->right) {
	//         sum += cur;
	//         return;
	//     }
	//     sumNumbers(node->left, cur, sum);
	//     sumNumbers(node->right, cur, sum);
	// }
};