#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};
// Runtime: 20 ms
// Best: 12 ms??
// https://leetcode.com/discuss/2297/the-iterative-solution-is-easier-than-you-think 16 ms
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int size = inorder.size();
		if (size == 0) {
			return nullptr;
		}
		unordered_map<int, int> m;
		for (int i = 0; i < size; i++) {
			m[inorder[i]] = i;
		}
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, size - 1, m);
	}
	TreeNode* buildTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir, unordered_map<int, int>& m) {
		if (pl > pr || il > ir) {
			return nullptr;
		}
		int mid = m[preorder[pl]];
		TreeNode* r = new TreeNode(inorder[mid]);
		r->left = buildTree(preorder, pl + 1, pl + mid - il, inorder, il, mid - 1, m);
		r->right = buildTree(preorder, pl + mid - il + 1, pr, inorder, mid + 1, ir, m);
		return r;
	}
};