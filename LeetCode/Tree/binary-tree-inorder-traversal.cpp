#include <vector>
#include <stack>
using std::vector;
using std::stack;
// Runtime: 0 ms
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> s;
		TreeNode* pCurr = root;
		while (!s.empty() || pCurr) {
			if (pCurr) {
				s.push(pCurr);
				pCurr = pCurr->left;
			}
			else {
				pCurr = s.top();
				ret.push_back(pCurr->val);
				s.pop();
				pCurr = pCurr->right;
			}
		}
		return ret;
	}
};