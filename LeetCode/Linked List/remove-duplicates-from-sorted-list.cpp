#include <iostream>


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Runtime: 12 ms
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *p = head;
		while (p != NULL && p->next != NULL) {
			if (p->val == p->next->val) {
				p->next = p->next->next;
			}
			else {
				p = p->next;
			}
		}
		return head;
	}
};