#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) {
			return nullptr;
		}
		int n = 1;
		ListNode* p = head;
		while (p->next) {
			n++;
			p = p->next;
		}
		k = n - k % n;
		p->next = head;
		for (int i = 0; i < k; i++) {
			p = p->next;
		}
		head = p->next;
		p->next = nullptr;
		return head;
	}
};