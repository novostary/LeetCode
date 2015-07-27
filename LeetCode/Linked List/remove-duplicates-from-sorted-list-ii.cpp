#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Runtime: 8 ms
// 1 1 2
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *pre = NULL, *newHead = NULL;
		while (head != NULL && head->next != NULL) {
			if (head->val == head->next->val) {
				head = head->next;
				while (head->next != NULL) {
					if (head->val == head->next->val) {
						head = head->next;
					}
					else {
						break;
					}
				}
				head = head->next;
			}
			else {
				if (newHead == NULL) {
					newHead = head;
					pre = head;
					head = head->next;
				}
				else {
					pre->next = head;
					pre = head;
					head = head->next;
				}
			}
		}
		if (pre != NULL) {
			pre->next = head;
			return newHead;
		}
		else {
			return head;
		}
	}
	// https://leetcode.com/discuss/21524/is-this-the-best-c-solution
	ListNode *deleteDuplicates2(ListNode *head) {
		ListNode fakeHead(0);
		fakeHead.next = head;
		ListNode* pre = &fakeHead;
		ListNode* p = pre->next;
		while (p) {
			ListNode* pn = p->next;

			if (pn && p->val == pn->val) {
				// move pn to next different value
				while (pn && p->val == pn->val) {
					pn = pn->next;
				}

				p = pn;
				pre->next = p;
			}
			else {
				pre = p;
				p = p->next;
			}
		}
		return fakeHead.next;
	}
	// https://leetcode.com/discuss/33666/simple-and-clear-c-recursive-solution
	ListNode* deleteDuplicates3(ListNode* head) {
		if (!head) return 0;
		if (!head->next) return head;

		int val = head->val;
		ListNode* p = head->next;

		if (p->val != val) {
			head->next = deleteDuplicates(p);
			return head;
		}
		else {
			while (p && p->val == val) p = p->next;
			return deleteDuplicates(p);
		}
	}
};