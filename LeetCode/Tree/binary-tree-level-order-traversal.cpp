#include <vector>
#include <queue>
using std::vector;
using std::queue;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};
// Runtime: 8 ms
// Best: 4 ms DFS
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
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
		return ret;
	}

	vector<vector<int>> levelOrder2(TreeNode* root) {
		vector<vector<int>> ret;
		levelOrder(ret, root, 0);
		return ret;
	}
	void levelOrder(vector<vector<int>>& ret, TreeNode* root, int level) {
		if (!root) {
			return;
		}
		if (ret.size() == level) {
			ret.push_back(vector<int>());
		}
		ret[level].push_back(root->val);
		levelOrder(ret, root->left, level + 1);
		levelOrder(ret, root->right, level + 1);
	}
};