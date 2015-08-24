/*
*	kth Smallest Element in A BST
*	Last Modified: 7/16/2015
*/

#include <vector>
#include "BinaryTree.h"

class Solution{
public:
	int kthSmallest(TreeNode* root, int k){
		if (!root || k <= 0) return INT_MIN;
		vector<int> value;
		inorderTraverse(root, value);
		return value[k - 1];
	}

	void inorderTraverse(TreeNode* node, vector<int>& value){
		if (!node) return;
		inorderTraverse(node->left, value);
		value.push_back(node->val);
		inorderTraverse(node->right, value);
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	Solution s;
	TreeNode *root = NULL;
	root = bTree.newNode(8);
	root->left = bTree.newNode(3);
	root->right = bTree.newNode(10);
	root->left->left = bTree.newNode(1);
	root->left->right = bTree.newNode(6);
	root->right->right = bTree.newNode(14);
	root->left->right->left = bTree.newNode(4);
	root->left->right->right = bTree.newNode(7);
	root->right->right->left = bTree.newNode(13);

	cout << "The Binary Search Tree is: " << endl;
	bTree.printPretty(root, 4, 0, cout);
	int k = 4;
	cout << endl << "The " << k << "th smallest element in the above tree is: " << s.kthSmallest(root, k) << endl;
	system("pause");
}