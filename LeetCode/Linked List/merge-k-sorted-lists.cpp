#include <iostream>
#include <vector>
using std::vector;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// Divide and Conquer
// Runtime: 404 ms
// Best: 400 ms??

// priority_queue
// https://leetcode.com/discuss/21363/brief-c-solution-with-priority_queue
// https://leetcode.com/discuss/27629/clean-c-code-using-maxheap-with-explanation
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// return mergeKLists(lists, 0, lists.size() - 1);

		// Runtime: 416 ms
		if (lists.empty()) {
			return NULL;
		}
		int n = lists.size();
		while (n > 1) {
			int k = (n + 1) / 2;
			for (int i = 0; i < n / 2; i++) {
				lists[i] = mergeTwoLists(lists[i], lists[k + i]);
			}
			n = k;
		}
		return lists[0];
	}

	ListNode* mergeKLists(vector<ListNode*>& lists, int i, int j) {
		if (i > j) {
			return NULL;
		}
		else if (i == j) {
			return lists[i];
		}
		else if (i + 1 == j) {
			return mergeTwoLists(lists[i], lists[j]);
		}
		else {
			int mid = (i + j) / 2;
			ListNode *l1 = mergeKLists(lists, i, mid);
			ListNode *l2 = mergeKLists(lists, mid + 1, j);
			return mergeTwoLists(l1, l2);
		}
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummyNode(0);
		ListNode *p = &dummyNode;
		while (l1 && l2) {
			if (l1->val < l2->val) {
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
		if (l1) {
			p->next = l1;
		}
		else {
			p->next = l2;
		}
		return dummyNode.next;
	}
};