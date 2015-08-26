/*
*	Flatten Binary Tree to Linked List
*	Last Modified: 7/12/2015
*/

#include "BinaryTree.h"

class Solution{
public:
	void flatten(TreeNode* root){
		while (root){
			if (root->left){
				TreeNode *p = root->left;
				while (p->right) p = p->right;	//Find the rightmost child of the left subtree
				p->right = root->right;		//Connect the right child to the rightmost child of the left subtree
				root->right = root->left;	//Set right child to be left child
				root->left = NULL;		//Set left child to be NULL
			}
			root = root->right;		//Iterate to the next right child until finished
		}
	}
};

void main(int argc, char* argv[]){
	binaryTree bTree;
	TreeNode* root = NULL;
	Solution s;
	root = bTree.newNode(1);
	root->left = bTree.newNode(2);
	root->right = bTree.newNode(5);
	root->left->left = bTree.newNode(3);
	root->left->right = bTree.newNode(4);
	root->right->right = bTree.newNode(6);

	cout << "The binary tree is: " << endl;
	bTree.printTree(root, 4);
	cout << endl << "The flattened tree is: " << endl;
	s.flatten(root);
	bTree.printTree(root, 4);
	cout << endl;
	system("pause");
}