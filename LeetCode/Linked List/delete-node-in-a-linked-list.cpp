struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
// Runtime: 16 ms
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		node->val = next->val;
		node->next = next->next;
	}
};