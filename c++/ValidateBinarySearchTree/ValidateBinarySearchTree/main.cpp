/*
*	Validate Binary Search Tree
*	Last Modified: 7/12/2015
*/

#include "BinaryTree.h"

class Solution{
public:
	bool isValidBST(TreeNode* root){
		return helper(root, INT_MIN, INT_MAX);
	}

	bool helper(TreeNode *node, int minValue, int maxValue){
		if (!node) return true;
		if (node->val == INT_MIN && node->left) return false;
		if (node->val == INT_MAX && node->right) return false;
		if (node->val < minValue || node->val > maxValue) return false;
		return helper(node->left, minValue, node->val - 1) && helper(node->right, node->val + 1, maxValue);
	}
};

void main(int argc, char* argv[]){
	binaryTree bTree;
	Solution s;
	TreeNode *root = NULL;
	root = bTree.newNode(INT_MIN);
	root->left = bTree.newNode(INT_MIN);
	/*root->right = bTree.newNode(5);
	root->left->left = bTree.newNode(3);
	root->left->right = bTree.newNode(1);*/

	cout << "The tree is: " << endl;
	bTree.printTree(root, 4);
	cout << "This tree is ";
	if (s.isValidBST(root)) cout << "a binary search tree" << endl;
	else cout << "not a binary search tree" << endl;
	system("pause");
}