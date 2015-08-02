#include <vector>
#include <stack>
using std::vector;
using std::stack;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};
// Runtime: 0 ms
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) {
			return ret;
		}
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()) {
			TreeNode* tn = s.top();
			s.pop();
			ret.push_back(tn->val);
			if (tn->right) {
				s.push(tn->right);
			}
			if (tn->left) {
				s.push(tn->left);
			}
		}
		return ret;
	}
};