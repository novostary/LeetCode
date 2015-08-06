#include <stack>
using std::stack;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 20 ms
// https://leetcode.com/discuss/43771/implemented-java-binary-search-order-iterative-recursive
class Solution {
public:
	// int kthSmallest(TreeNode* root, int k) {
	//     stack<TreeNode*> s;
	//     TreeNode* p = root;
	//     while (p || !s.empty()) {
	//         while (p) {
	//             s.push(p);
	//             p = p->left;
	//         }
	//         p = s.top();
	//         if (--k == 0) {
	//             return p->val;
	//         } else {
	//             s.pop();
	//             p = p->right;
	//         }
	//     }
	// }

	// int kthSmallest(TreeNode* root, int k) {
	//     int count = countNodes(root->left);
	//     if (k <= count) {
	//         return kthSmallest(root->left, k);
	//     } else if (k > count + 1) {
	//         return kthSmallest(root->right, k - count - 1);
	//     } else {
	//         return root->val;
	//     }
	// }
	// int countNodes(TreeNode* root) {
	//     if (!root) {
	//         return 0;
	//     }
	//     return 1 + countNodes(root->left) + countNodes(root->right);
	// }
	int kthSmallest(TreeNode* root, int k) {
		int ret = 0;
		helper(root, k, ret);
		return ret;
	}
	void helper(TreeNode* root, int &k, int &ret) {
		if (root->left) {
			helper(root->left, k, ret);
		}
		k--;
		if (k == 0) {
			ret = root->val;
			return;
		}
		if (root->right) {
			helper(root->right, k, ret);
		}
	}
};