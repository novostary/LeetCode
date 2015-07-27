#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Runtime: 28 ms
// Best: 24 ms done
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k < 2) {
			return head;
		}
		ListNode dummyNode(0);
		dummyNode.next = head;
		ListNode* pre = &dummyNode;
		int i = k;
		while (head->next) {
			if (i > 1) {
				ListNode* tmp = head->next;
				head->next = tmp->next;
				tmp->next = pre->next;
				pre->next = tmp;
				i--;
			}
			else {
				pre = head;
				head = head->next;
				i = k;
			}
		}
		if (i > 1) {
			head = pre->next;
			/*while (head) {
				ListNode* tmp = head->next;
				if (!tmp) {
					break;
				}
				head->next = tmp->next;
				tmp->next = pre->next;
				pre->next = tmp;
			}*/
			// 24 ms
			while (head->next) {
				ListNode* tmp = head->next;
				head->next = tmp->next;
				tmp->next = pre->next;
				pre->next = tmp;
			}
		}
		return dummyNode.next;
	}
};