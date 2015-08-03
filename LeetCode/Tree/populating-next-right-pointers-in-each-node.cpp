struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};
// Runtime: 24 ms
// To get to the leaf nodes, a recursive solution needs to be log2(n) calls deep, 
// and each call has a call stack, which takes up memory. This means that a recursive 
// solution isn't constant memory, but O(log(n)) memory.
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) {
			return;
		}
		TreeLinkNode* pre = root;
		TreeLinkNode* cur = nullptr;
		while (pre->left) {
			cur = pre;
			while (cur) {
				cur->left->next = cur->right;
				if (cur->next) {
					cur->right->next = cur->next->left;
				}
				cur = cur->next;
			}
			pre = pre->left;
		}
	}
	void connect2(TreeLinkNode *root) {
		if (!root) {
			return;
		}
		else {
			connect(root->left, root->right, nullptr);
		}
	}
	void connect(TreeLinkNode *left, TreeLinkNode *right, TreeLinkNode* rightmost) {
		if (!left) {
			return;
		}
		left->next = right;
		right->next = rightmost;
		connect(left->left, left->right, right->left);
		if (rightmost) {
			connect(right->left, right->right, rightmost->left);
		}
		else {
			connect(right->left, right->right, nullptr);
		}
	}
};