#include <vector>
#include <stack>
using std::vector;
using std::stack;
// Runtime: 4 ms
// Best: 0 ms??
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

// Morris traversal
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) {
			return ret;
		}
		stack<TreeNode*> s;
		s.push(root);
		vector<int>::iterator it = ret.begin(); // 0 ms
		while (!s.empty()) {
			TreeNode* tn = s.top();
			s.pop();
			// ret.insert(ret.begin(), tn->val);
			it = ret.insert(it, tn->val);
			if (tn->left) {
				s.push(tn->left);
			}
			if (tn->right) {
				s.push(tn->right);
			}
		}
		// reverse(ret.begin(),ret.end());
		return ret;
	}
};