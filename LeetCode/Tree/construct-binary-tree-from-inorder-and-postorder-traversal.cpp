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
// Runtime: 16 ms
// TreeNode* buildTree(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr, unordered_map<int, int>& m)
// Best: 12 ms???
// https://leetcode.com/discuss/15115/my-comprehension-of-o-n-solution-from-%40hongzhi ???
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int inorderSize = inorder.size();
		if (inorderSize == 0) {
			return nullptr;
		}
		unordered_map<int, int> m;
		for (int i = 0; i < inorderSize; i++) {
			m[inorder[i]] = i;
		}
		return buildTree(inorder, 0, inorderSize - 1, postorder, 0, postorder.size() - 1, m);

	}
	TreeNode* buildTree(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr, unordered_map<int, int>& m) {
		int mid = m[postorder[pr]];
		TreeNode* root = new TreeNode(inorder[mid]);
		if (mid != il) {
			root->left = buildTree(inorder, il, mid - 1, postorder, pl, pl + mid - 1 - il, m);
		}
		if (mid != ir) {
			root->right = buildTree(inorder, mid + 1, ir, postorder, pl + mid - il, pr - 1, m);
		}
		return root;
	}
};