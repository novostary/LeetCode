#include <algorithm>
using std::max;
// Runtime: 8 ms
// https://leetcode.com/discuss/28438/my-code-of-c-depth-first-search-and-breadth-first-search
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + max(maxDepth(root->left), maxDepth(root->right));
		}
		// return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
	}
	/* int maxDepth(TreeNode *root)
	{
		if (root == NULL)
			return 0;

		int res = 0;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			++res;
			for (int i = 0, n = q.size(); i < n; ++i)
			{
				TreeNode *p = q.front();
				q.pop();

				if (p->left != NULL)
					q.push(p->left);
				if (p->right != NULL)
					q.push(p->right);
			}
		}

		return res;
	}*/
};