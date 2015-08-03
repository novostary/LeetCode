struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
// Runtime: 28 ms
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return sortedListToBST(head, nullptr);
	}
	TreeNode* sortedListToBST(ListNode* head, ListNode* end) {
		if (head == end) {
			return nullptr;
		}
		ListNode *fast = head, *slow = head;
		while (fast->next != end && fast->next->next != end) {
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* node = new TreeNode(slow->val);
		node->left = sortedListToBST(head, slow);
		node->right = sortedListToBST(slow->next, end);
		return node;
	}
};