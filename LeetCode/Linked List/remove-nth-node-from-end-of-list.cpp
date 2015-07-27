struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
// Runtime: 4 ms
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummyNode(0);
		dummyNode.next = head;
		ListNode* pre = &dummyNode;
		for (int i = 1; i < n; i++) {
			head = head->next;
		}
		while (head->next) {
			pre = pre->next;
			head = head->next;
		}
		pre->next = pre->next->next;
		return dummyNode.next;
	}
};