#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Runtime: 4 ms
// Best: 0 ms???
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummyNode(0);
		ListNode *p = &dummyNode;
		p->next = head;
		for (int i = 1; i < m; i++) {
			p = p->next;
		}
		head = p->next;
		for (int i = m; i < n; i++) {
			ListNode *tmp = head->next;
			head->next = tmp->next;
			tmp->next = p->next;
			p->next = tmp;
		}
		return dummyNode.next;
	}
};