struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 40 ms
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *small, *big;
		p->val < q->val ? (small = p, big = q) : (small = q, big = p);
		while (root) {
			if (big->val < root->val) {
				root = root->left;
			}
			else if (small->val > root->val) {
				root = root->right;
			}
			else {
				return root;
			}
		}
		// if (p->val < root->val && q->val < root->val) {
		//     return lowestCommonAncestor(root->left, p, q);
		// } else if (p->val > root->val && q->val > root->val) {
		//     return lowestCommonAncestor(root->right, p, q);
		// } else {
		//     return root;
		// }

		// if (p->val <= q->val) {
		//     if (root->val >= p->val && root->val <= q->val) {
		//         return root;
		//     } else if (root->val > q->val) {
		//         return lowestCommonAncestor(root->left, p, q);
		//     } else {
		//         return lowestCommonAncestor(root->right, p, q);
		//     }
		// } else {
		//     return lowestCommonAncestor(root, q, p);
		// }
	}
};