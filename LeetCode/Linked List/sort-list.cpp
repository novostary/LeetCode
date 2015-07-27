#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Runtime: 64 ms
// Best: 52 ms????
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !(head->next)) {
			return head;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		slow->next = nullptr;
		return mergeTwoLists(sortList(head), sortList(fast));
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummyNode(0);
		ListNode *p = &dummyNode;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				p = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				p = l2;
				l2 = l2->next;
			}
		}
		if (l1) {
			p->next = l1;
		}
		else {
			p->next = l2;
		}
		return dummyNode.next;
	}
};