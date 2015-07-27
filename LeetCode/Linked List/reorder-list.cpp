struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
// Runtime: 64 ms
class Solution {
public:
	void reorderList(ListNode* head) {
		// one element?
		if (!head || !head->next || !head->next->next) {
			return;
		}
		ListNode* fast = head, *slow = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = reverseList(slow->next);
		slow->next = nullptr;
		slow = head;
		while (fast) {
			ListNode* tmp = fast->next;
			fast->next = slow->next;
			slow->next = fast;
			slow = fast->next;
			fast = tmp;
		}
	}

	ListNode* reverseList(ListNode* head) {
		ListNode dummyNode(0);
		ListNode *p = &dummyNode;
		while (head) {
			ListNode *tmp = head;
			head = head->next;
			tmp->next = p->next;
			p->next = tmp;
		}
		return dummyNode.next;
	}
};