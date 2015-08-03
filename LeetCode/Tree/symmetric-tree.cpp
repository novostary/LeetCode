#include <queue>
#include <utility>
using std::queue;
using std::pair;
using std::make_pair;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 4 ms
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}
		else {
			return isSymmetric(root->left, root->right);
		}
	}
	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (!left && !right) {
			return true;
		}
		else if (!left || !right) {
			return false;
		}
		else {
			return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
		}

	}

	bool isSymmetric2(TreeNode* root) {
		if (!root) {
			return true;
		}
		queue<pair<TreeNode*, TreeNode*>> q;
		q.push(make_pair(root->left, root->right));
		while (!q.empty()) {
			pair<TreeNode*, TreeNode*> p = q.front();
			q.pop();
			if (p.first) {
				if (!p.second) {
					return false;
				}
				if (p.first->val == p.second->val) {
					q.push(make_pair(p.first->left, p.second->right));
					q.push(make_pair(p.first->right, p.second->left));
				}
				else {
					return false;
				}
			}
			else if (p.second) {
				return false;
			}
		}
		return true;
	}
};