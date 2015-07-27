#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Runtime: 8 ms
class Solution {
public:
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