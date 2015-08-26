/*
*	Invert Binary Tree
*	Last Modified: 7/9/2015
*/

#include "BinaryTree.h"
#include <algorithm>

class Solution{
public:
	TreeNode* invertTree(TreeNode* root){
		if (!root || (!root->left && !root->right)) return root;
		TreeNode *node = root->left;
		root->left = root->right;
		root->right = node;
		if (root->left) node = invertTree(root->left);
		if (root->right) node = invertTree(root->right);
		return root;
	}
};

void main(int argc, char* argv[]){
	TreeNode *root = NULL;
	binaryTree bTree;
	Solution s;
	root = bTree.newNode(4);
	root->left = bTree.newNode(2);
	root->right = bTree.newNode(7);
	root->left->left = bTree.newNode(1);
	root->left->right = bTree.newNode(3);
	root->right->left = bTree.newNode(6);
	root->right->right = bTree.newNode(9);
	cout << "The original tree is: " << endl;
	bTree.printTree(root, 0);
	cout << endl << "The inverted tree is: " << endl; 
	bTree.printTree(s.invertTree(root), 0);
	cout << endl;
	system("pause");
}