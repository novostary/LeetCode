#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Runtime: 12 ms
// Best: 8 ms
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) {
			return l2;
		}
		if (l2 == NULL) {
			return l1;
		}
		ListNode *head = NULL, *p = NULL;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				if (head == NULL) {
					head = l1;
					p = l1;
					l1 = l1->next;
				}
				else {
					p->next = l1;
					p = l1;
					l1 = l1->next;
				}
			}
			else {
				if (head == NULL) {
					head = l2;
					p = l2;
					l2 = l2->next;
				}
				else {
					p->next = l2;
					p = l2;
					l2 = l2->next;
				}
			}
		}
		if (l1 == NULL) {
			p->next = l2;
		}
		else {
			p->next = l1;
		}
		return head;
	}

	ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode* p = &dummy;

		while (l1 && l2) {
			int val1 = l1->val;
			int val2 = l2->val;
			//哪个节点小，就挂载，同时移动到下一个节点
			if (val1 < val2) {
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

		//这里处理还未挂载的节点
		if (l1) {
			p->next = l1;
		}
		else if (l2) {
			p->next = l2;
		}

		return dummy.next;
	}
};