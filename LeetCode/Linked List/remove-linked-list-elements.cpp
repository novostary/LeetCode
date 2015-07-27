struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
// Runtime: 36 ms
// Best: 32 ms???
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummyNode(0);
		ListNode* pre = &dummyNode;
		while (head) {
			if (head->val == val) {
				head = head->next;
			}
			else {
				pre->next = head;
				pre = head;
				head = head->next;
			}
		}
		pre->next = nullptr;
		return dummyNode.next;
	}
};
