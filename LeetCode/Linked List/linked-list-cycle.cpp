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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return false;
		}
		else {
			ListNode *p, *q;
			p = head;
			q = head;
			/*while (p != q) {
				if (q != NULL && q->next != NULL) {
					q = q->next->next;
					p = p->next;
				}
				else {
					return false;
				}
			}
			return true;*/

			while (q->next != NULL && q->next->next != NULL) {
				p = p->next;
				q = q->next->next;
				if (p == q) {
					return true;
				}
			}
			return false;
		}
	}
};