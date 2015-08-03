#include <vector>
using std::vector;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 24 ms
// Best: 12 ms void pathSum(vector<vector<int>>& ret, vector<int>& vec, TreeNode* root, int sum)
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		vector<int> vec;
		pathSum(ret, vec, root, sum);
		return ret;
	}
	void pathSum(vector<vector<int>>& ret, vector<int> vec, TreeNode* root, int sum) {
		if (!root) {
			return;
		}
		sum = sum - root->val;
		vec.push_back(root->val);
		if (!root->left && !root->right) {
			if (sum == 0) {
				ret.push_back(vec);
			}
			return;
		}
		pathSum(ret, vec, root->left, sum);
		pathSum(ret, vec, root->right, sum);
	}
	void pathSum2(vector<vector<int>>& ret, vector<int>& vec, TreeNode* root, int sum) {
		if (!root) {
			return;
		}
		sum = sum - root->val;
		vec.push_back(root->val);
		if (!root->left && !root->right) {
			if (sum == 0) {
				ret.push_back(vec);
			}
			vec.pop_back();
			return;
		}
		pathSum2(ret, vec, root->left, sum);
		pathSum2(ret, vec, root->right, sum);
		vec.pop_back();
	}
};