#include <algorithm>
#include <queue>
using std::min;
using std::queue;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 12 ms
// https://leetcode.com/discuss/11134/my-bfs-solution-c
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) {
			return 0;
		}
		/*if (root->left && !root->right) {
		return 1 + minDepth(root->left);
		} else if (!root->left && root->right) {
		return 1 + minDepth(root->right);
		} else {
		return 1 + min(minDepth(root->left), minDepth(root->right));
		}*/
		queue<TreeNode*> q;
		q.push(root);
		int dep = 0;
		while (!q.empty()) {
			dep++;
			for (int i = 0, n = q.size(); i < n; i++) {
				TreeNode* front = q.front();
				if (!front->left && !front->right) {
					return dep;
				}
				else if (!front->left) {
					q.push(front->right);
				}
				else if (!front->right) {
					q.push(front->left);
				}
				else {
					q.push(front->left);
					q.push(front->right);
				}
				q.pop();
			}
		}
		//return dep;
	}
};