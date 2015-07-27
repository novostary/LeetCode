struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
// Runtime: 24 ms
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head) {
			return true;
		}
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = reverseList(slow->next);
		// slow->next = nullptr;
		while (fast) {
			if (head->val != fast->val) {
				return false;
			}
			else {
				head = head->next;
				fast = fast->next;
			}
		}
		return true;
	}

	ListNode* reverseList(ListNode* head) {
		ListNode dummyNode(0);
		ListNode *p = &dummyNode;
		while (head) {
			ListNode *tmp = head;
			head = head->next;
			tmp->next = p->next;
			p->next = tmp;
		}
		return dummyNode.next;
	}
};
