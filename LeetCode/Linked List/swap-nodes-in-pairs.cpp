#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode dummyNode(0);
		dummyNode.next = head;
		ListNode* pre = &dummyNode;
		while (head && head->next) {
			ListNode* tmp = head->next;
			head->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;

			pre = head;
			head = head->next;
		}
		return dummyNode.next;
	}
};