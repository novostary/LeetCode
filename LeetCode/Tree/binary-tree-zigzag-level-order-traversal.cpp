#include <vector>
#include <stack>
#include <queue>
using std::vector;
using std::stack;
using std::queue;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root) {
			return ret;
		}
		stack<TreeNode*> sodd, seven;
		sodd.push(root);
		while (!sodd.empty() || !seven.empty()) {
			vector<int> level;
			if (seven.empty()) {
				for (int size = sodd.size(); size > 0; --size) {
					TreeNode* p = sodd.top();
					sodd.pop();
					level.push_back(p->val);
					if (p->left) {
						seven.push(p->left);
					}
					if (p->right) {
						seven.push(p->right);
					}
				}
			}
			else {
				for (int size = seven.size(); size > 0; --size) {
					TreeNode* p = seven.top();
					seven.pop();
					level.push_back(p->val);
					if (p->right) {
						sodd.push(p->right);
					}
					if (p->left) {
						sodd.push(p->left);
					}
				}
			}
			ret.push_back(level);
		}
		return ret;
	}

	vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root) {
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);
		int odd = 1;
		while (!q.empty()) {
			int size = q.size();
			vector<int> level(size, 0);
			for (int i = (odd == 1 ? 0 : size - 1); i != (odd == 1 ? size : -1); i += odd) {
				TreeNode* p = q.front();
				q.pop();
				level[i] = p->val;
				if (p->left) {
					q.push(p->left);
				}
				if (p->right) {
					q.push(p->right);
				}
			}
			if (odd == 1) {
				odd = -1;
			}
			else {
				odd = 1;
			}
			ret.push_back(level);
		}
		return ret;
	}
};