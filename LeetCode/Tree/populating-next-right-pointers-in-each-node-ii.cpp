struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};
// Runtime: 36 ms
class Solution {
public:
	void connect(TreeLinkNode *root) {
		while (root) {
			TreeLinkNode dummyNode(0);
			TreeLinkNode* prev = &dummyNode;
			while (root) {
				if (root->left) {
					prev->next = root->left;
					prev = root->left;
				}
				if (root->right) {
					prev->next = root->right;
					prev = root->right;
				}
				root = root->next;
			}
			root = dummyNode.next;
		}
	}
	/*void connect(TreeLinkNode *root) {
	TreeLinkNode* head = root;
	TreeLinkNode* prev = nullptr;
	TreeLinkNode* cur = nullptr;
	while (head) {
	cur = head;
	prev = nullptr;
	head = nullptr;
	while (cur) {
	if (cur->left) {
	if (prev) {
	prev->next = cur->left;
	} else {
	head = cur->left;
	}
	prev = cur->left;
	}
	if (cur->right) {
	if (prev) {
	prev->next = cur->right;
	} else {
	head = cur->right;
	}
	prev = cur->right;
	}
	cur = cur->next;
	}
	}
	}*/
};