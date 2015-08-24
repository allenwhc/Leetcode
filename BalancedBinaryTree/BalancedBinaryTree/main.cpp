/*
*	Balanced Binary Tree
*	Last Modified: 6/29/2015
*/

#include "BinaryTree.h"
#include <algorithm>
using namespace std;

class Solution{
public:
	bool isBalanced(TreeNode* root){
		if (root == NULL) return true;
		int leftTreeHeight = height(root->left);
		int rightTreeHeight = height(root->right);
		if (abs(leftTreeHeight - rightTreeHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return true;
		return false;
	}

	int height(TreeNode* node){
		if (node == NULL) return 0;
		return 1 + max(height(node->left), height(node->right));
	}
};

void main(int argc, char* argv[]){
	binaryTree bTree;
	Solution s;
	TreeNode *root = NULL;
	root = bTree.newNode(50);
	root->left = bTree.newNode(17);
	root->right = bTree.newNode(72);
	root->left->left = bTree.newNode(12);
	root->left->right = bTree.newNode(23);
	root->right->left = bTree.newNode(54);
	root->right->right = bTree.newNode(76);
	root->left->left->left = bTree.newNode(9);
	root->left->left->right = bTree.newNode(14);
	root->left->right = bTree.newNode(19);
	root->right->left->right = bTree.newNode(67);
	bTree.printTree(root, 0);
	bool balance = s.isBalaned(root);
	cout << "The above binary tree is ";
	if (balance) cout << "balanced" << endl;
	else cout << "not balanced" << endl;
	system("pause");
}