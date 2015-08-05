#include <stack>
using std::stack;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 24 ms
// 共性抽象成函数
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		findLeft(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* p = s.top();
		s.pop();
		findLeft(p->right);
		return p->val;
	}
private:
	void findLeft(TreeNode* root) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}
	stack<TreeNode *> s;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/