#include <vector>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

public:

  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
	if(root == nullptr)
		return nullptr;
	for(auto node : nodes) {
		if(root == node)
			return node;
	}
	TreeNode* left = lowestCommonAncestor(root->left , nodes);
	TreeNode* right = lowestCommonAncestor(root->right , nodes);

	if(left == nullptr)
		return right;
	if(right == nullptr)
		return left;

	return root;
  }

};

