#include <vector>
#include <queue>
using std::vector;
using std::queue;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 4 ms
// another method: modified preorder traversal
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		if (!root) {
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* p = q.back();
			ret.push_back(p->val);
			int n = q.size();
			while (n-- > 0) {
				p = q.front();
				q.pop();
				if (p->left) {
					q.push(p->left);
				}
				if (p->right) {
					q.push(p->right);
				}
			}
		}
		return ret;
	}
};