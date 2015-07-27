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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		else {
			ListNode *p, *q;
			p = head;
			q = head;

			while (q->next != NULL && q->next->next != NULL) {
				p = p->next;
				q = q->next->next;
				if (p == q) {
					p = head;
					while (p != q) {
						p = p->next;
						q = q->next;
					}
					return p;
				}
			}
			return NULL;
		}
	}
};