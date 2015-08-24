/*
*	Count Complete Tree Nodes
*	Last Modified: 7/21/2015
*	Hint:
		1) get the height of left-most part
		2) get the height of right-most part
		3) when they are equal, the # of nodes = 2^h -1
		4) when they are not equal, recursively get # of nodes from left&right sub-trees
*/

#include <algorithm>
#include "BinaryTree.h"

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		int lh = leftMostHeight(root) + 1;
		int rh = rightMostHeight(root) + 1;
		if (lh == rh) return (2 << (lh - 1)) - 1;
		else return countNodes(root->left) + countNodes(root->right) + 1;
	}

	int leftMostHeight(TreeNode* node){
		if (!node) return 0;
		int lh = 0;
		while (node->left){
			node = node->left;
			lh++;
		}
		return lh;
	}

	int rightMostHeight(TreeNode *node){
		if (!node) return 0;
		int rh = 0;
		while (node->right){
			node = node->right;
			rh++;
		}
		return rh;
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	Solution s;
	TreeNode *root = NULL;
	root = bTree.newNode(1);
	root->left = bTree.newNode(2);
	root->right = bTree.newNode(3);
	root->left->left = bTree.newNode(4);
	root->left->right = bTree.newNode(5);
	root->right->left = bTree.newNode(6);
	root->right->right = bTree.newNode(7);
	root->left->left->left = bTree.newNode(8);
	root->left->left->right = bTree.newNode(9);
	root->left->right->left = bTree.newNode(10);
	cout << "The binary tree is: " << endl;
	bTree.printPretty(root, 1, 0, cout);
	cout << "The number of tree nodes in the above tree is: " << s.countNodes(root) << endl;
	system("pause");
}