#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !(head->next)) {
			return head;
		}
		ListNode dummyNode(0);
		ListNode* pre = &dummyNode;
		while (head) {
			while (pre->next && pre->next->val < head->val) {
				pre = pre->next;
			}
			ListNode* tmp = head->next;
			head->next = pre->next;
			pre->next = head;
			head = tmp;
			pre = &dummyNode;
		}
		return dummyNode.next;
	}
};