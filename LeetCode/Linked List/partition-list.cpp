struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
// Runtime: 8 ms
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode dummy1(0), dummy2(0);
		ListNode* pre1 = &dummy1;
		ListNode* pre2 = &dummy2;
		while (head) {
			if (head->val < x) {
				pre1->next = head;
				pre1 = head;
			}
			else {
				pre2->next = head;
				pre2 = head;
			}
			head = head->next;
		}
		pre2->next = nullptr;
		pre1->next = dummy2.next;
		return dummy1.next;
	}

	ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
		ListNode preHead(0), *p = &preHead;
		int extra = 0;
		while (l1 || l2 || extra) {
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
			extra = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return preHead.next;
	}
};