#include <algorithm>
using std::pow;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Runtime: 268 ms
// return pow(2, left) - 1; --> return (1 << left) - 1; 108 ms
// Best: 72 ms???
// https://leetcode.com/discuss/42785/72-ms-c-solution
// https://leetcode.com/discuss/48521/68-ms-c-solution-using-binary-search
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int l = 1, r = 1;
		TreeNode* p = root->left;
		while (p) {
			p = p->left;
			++l;
		}
		p = root->right;
		while (p) {
			p = p->right;
			++r;
		}
		if (l == r) {
			return pow(2, l) - 1;
		}
		else {
			return 1 + countNodesLeft(root->left, l - 1) + countNodesRight(root->right, r - 1);
		}
	}
private:
	int countNodesLeft(TreeNode* root, int left) {
		if (!root) {
			return 0;
		}
		int right = 1;
		TreeNode* p = root->right;
		while (p) {
			p = p->right;
			++right;
		}
		if (left == right) {
			return pow(2, left) - 1;
		}
		else {
			return 1 + countNodesLeft(root->left, left - 1) + countNodesRight(root->right, right - 1);
		}
	}
	int countNodesRight(TreeNode* root, int right) {
		if (!root) {
			return 0;
		}
		int left = 1;
		TreeNode* p = root->left;
		while (p) {
			p = p->left;
			++left;
		}
		if (left == right) {
			return pow(2, left) - 1;
		}
		else {
			return 1 + countNodesLeft(root->left, left - 1) + countNodesRight(root->right, right - 1);
		}
	}
};