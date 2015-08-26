/*
*	Binary Tree Iterator
*	Last Modified: 7/22/2015
*/

#include "BinaryTree.h"
#include <stack>

class BSTIterator {
private:
	stack<TreeNode*> stk;
public:
	BSTIterator(TreeNode *root) {
		//Initialization of the stack
		//Push all the left children to the stack
		while (root){
			stk.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stk.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *node = stk.top();		//Get the top of the stack
		int res = node->val;
		stk.pop();	//Pop the top
		if (node->right){
			node = node->right;
			while (node){
				stk.push(node);
				node = node->left;
			}
		}
		return res;
	}
};

void main(int argc, char* argv[]){
	binaryTree bTree;
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
	cout << "The binary search tree is: " << endl;
	bTree.printPretty(root, 1, 0, cout);
	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) cout << i.next() << " ";
	cout << endl;
	system("pause");
}