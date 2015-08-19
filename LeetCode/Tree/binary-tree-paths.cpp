#include <vector>
#include <string>
using std::vector;
using std::string;
using std::to_string;
// Runtime: 4 ms
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		binaryTreePaths(ret, root, "");
		return ret;
	}
	void binaryTreePaths(vector<string>& ret, TreeNode* root, string curStr) {
		if (root) {
			if (curStr.empty()) {
				curStr = to_string(root->val);
			}
			else {
				curStr += "->" + to_string(root->val);
			}
			if (!root->left && !root->right) {
				ret.push_back(curStr);
			}
			else {
				binaryTreePaths(ret, root->left, curStr);
				binaryTreePaths(ret, root->right, curStr);
			}
		}
	}
};