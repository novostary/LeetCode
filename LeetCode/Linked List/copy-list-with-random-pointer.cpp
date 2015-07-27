#include <unordered_map>
using std::unordered_map;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};
// Runtime: 116 ms
// Best: 104 ms???
// http://siddontang.gitbooks.io/leetcode-solution/content/linked_list/copy_list_with_random_pointer.html
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) {
			return nullptr;
		}
		RandomListNode dummyNode(0);
		RandomListNode* pre = &dummyNode;
		RandomListNode* h = head;
		unordered_map<RandomListNode*, RandomListNode*> m;
		while (h) {
			pre->next = new RandomListNode(h->label);
			pre = pre->next;
			pre->random = h->random;
			m[h] = pre;
			h = h->next;
		}
		h = dummyNode.next;
		while (h) {
			if (h->random) {
				h->random = m[h->random];
			}
			h = h->next;
		}
		return dummyNode.next;
	}
	// ����ķ���
	RandomListNode *copyRandomList2(RandomListNode *head) {
		if (head == NULL) {
			return NULL;
		}

		//�����������µĽڵ�
		RandomListNode* n = NULL;
		RandomListNode* h = head;
		while (h) {
			RandomListNode* node = new RandomListNode(h->label);
			node->random = h->random;

			n = h->next;

			h->next = node;
			node->next = n;
			h = n;
		}

		//����random
		h = head->next;
		while (h) {
			if (h->random != NULL) {
				h->random = h->random->next;
			}
			if (!h->next) {
				break;
			}
			h = h->next->next;
		}

		//�Ͽ�����
		h = head;
		RandomListNode dummy(0);
		RandomListNode* p = &dummy;
		while (h) {
			n = h->next;
			p->next = n;
			p = n;
			RandomListNode* nn = n->next;
			h->next = n->next;
			h = n->next;
		}

		return dummy.next;
	}
};