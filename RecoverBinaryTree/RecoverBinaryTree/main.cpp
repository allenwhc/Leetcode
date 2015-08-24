/*
*	Recover Binary Tree
*	Last Modified: 7/24/2015
	Hint: 
		1. Traverse the left subtree
		2. Check the value of current node:
			1) If no violation happens, then mark this node as previous, and move to next node
			2) If violation happens:
				i) If *first == NULL, it means this is the first violation
				   Set *first=*prev, *middle=root;
				ii) If *first != NULL, it means this is the second violation
					Set *last=root
		3. Traverse the right subtree
		4. Check *last:
			If last==NULL, then adjacent nodes should be swapped, swap(first->val, middle->val);
			Else, swap(first->val, last->val)
*/

#include "BinaryTree.h"

class Solution {
public:
	void recoverTree(TreeNode* root) {
		//Initialize four pointers
		TreeNode *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;
		correctTree(root, &first, &middle, &last, &prev);
		//cout << first->val << endl;
		if (first && last) {
			//The swapped nodes are not adjacent
			swapNode(&(first->val), &(last->val));
		}
		else if (first && middle){
			 //The swapped nodes are adjacent
			swapNode(&(first->val), &(middle->val));
		}
	}

	void correctTree(TreeNode *root, TreeNode **first, TreeNode **middle, TreeNode **last, TreeNode **prev){
		if (root){
			correctTree(root->left, first, middle, last, prev);	//Traverse left subtree
			if (*prev && root->val < (*prev)->val){
				if (!*first){	//If the first violation
					*first = *prev;	//Mark first as the previous node
					*middle = root;	//Mark middle as the current node
				}
				else{   //If the second violation
					*last = root;	//Mark last as the current node
				}
			}
			*prev = root;	//Mark this node as previous node
			correctTree(root->right, first, middle, last, prev);	//Traverse right subtree
		}
	}

	void swapNode(int *a, int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	Solution s;
	TreeNode *root = NULL;
	root = bTree.newNode(10);
	root->left = bTree.newNode(5);
	root->right = bTree.newNode(8);
	root->left->left = bTree.newNode(2);
	root->left->right = bTree.newNode(20);

	cout << "The incorrect binary search tree is: " << endl;
	bTree.printPretty(root, 1, 0, cout);
	s.recoverTree(root);
	cout << "The correct binary search tree is: " << endl;
	bTree.printPretty(root, 1, 0, cout);
	system("pause");
}