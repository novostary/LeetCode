#include <iostream>


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Runtime: 52 ms
// Best: 48 ms???
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) {
			return NULL;
		}
		/*int countA = 0;
		ListNode *pA = headA;
		while (pA->next != NULL) {
			countA++;
			pA = pA->next;
		}

		int countB = 0;
		ListNode *pB = headB;
		while (pB->next != NULL) {
			countB++;
			pB = pB->next;
		}
		if (pA == pB) {
			pA = headA;
			pB = headB;
			if (countA > countB) {
				for (int i = 0; i < countA - countB; i++) {
					pA = pA->next;
				}
			}
			else {
				for (int i = 0; i < countB - countA; i++) {
					pB = pB->next;
				}
			}
			while (pA != pB) {
				pA = pA->next;
				pB = pB->next;
			}
			return pA;
		}
		else {
			return NULL;
		}*/
		ListNode *pA = headA;
		while (pA->next != NULL) {
			pA = pA->next;
		}
		pA->next = headB;
		/*ListNode *connect = detectCycle(headA);
		pA->next = NULL;
		return connect;*/
		ListNode *p, *q;
		p = headA;
		q = headA;

		while (q->next != NULL && q->next->next != NULL) {
			p = p->next;
			q = q->next->next;
			if (p == q) {
				p = headA;
				while (p != q) {
					p = p->next;
					q = q->next;
				}
				pA->next = NULL;
				return p;
			}
		}
		pA->next = NULL;
		return NULL;
	}

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