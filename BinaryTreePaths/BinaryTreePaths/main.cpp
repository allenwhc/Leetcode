/*
*	Binary Tree Paths
*	Last Modified: 8/16/2015
*/

#include "BinaryTree.h"
#include <vector>
#include <string>

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (!root) return res;
		string node;
		dfs(res, node, root);
		return res;
	}

	void dfs(vector<string>& paths, string node, TreeNode *root){
		if (!root) return;
		node.append(to_string(root->val));
		if (root->left || root->right)
			node.append("->");
		if (!root->left && !root->right)
		{
			paths.push_back(node);
			return;
		}

		if (root->left)
			dfs(paths, node, root->left);
		if (root->right)
			dfs(paths, node, root->right);
	}
};

void main(){
	TreeNode *root = NULL;
	binaryTree bTree;
	Solution sol;
	cout << "The binary tree is: " << endl;
	root = bTree.newNode(1);
	root->left = bTree.newNode(2);
	root->right = bTree.newNode(3);
	root->left->left = bTree.newNode(4);
	root->left->right = bTree.newNode(5);
	root->right->left = bTree.newNode(6);
	root->right->right = bTree.newNode(7);
	root->left->left->left = bTree.newNode(8);
	bTree.printPretty(root, 1, 0, cout);
	cout << "All paths in the binary tree are: " << endl;
	for (auto x : sol.binaryTreePaths(root))
		cout << x << ",";
	cout << endl;
	system("pause");
}