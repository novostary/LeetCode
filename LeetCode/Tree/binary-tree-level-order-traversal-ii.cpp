#include <vector>
#include <queue>
#include <algorithm>
using std::max;
using std::vector;
using std::queue;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};
// Runtime: 8 ms
// Best: 4 ms done! DFS
class Solution {
public:
	/*vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root) {
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> level;
			for (int i = 0, size = q.size(); i < size; i++) {
				TreeNode* p = q.front();
				q.pop();
				level.push_back(p->val);
				if (p->left) {
					q.push(p->left);
				}
				if (p->right) {
					q.push(p->right);
				}
			}
			ret.push_back(level);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}*/

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		int h = height(root);
		vector<vector<int>> ret(h, vector<int>());
		levelOrderBottom(ret, root, h - 1);
		return ret;
	}
	void levelOrderBottom(vector<vector<int>>& ret, TreeNode* root, int level) {
		if (!root) {
			return;
		}
		ret[level].push_back(root->val);
		levelOrderBottom(ret, root->left, level - 1);
		levelOrderBottom(ret, root->right, level - 1);
	}
	int height(TreeNode* root) {
		return root ? 1 + max(height(root->left), height(root->right)) : 0;
	}
};