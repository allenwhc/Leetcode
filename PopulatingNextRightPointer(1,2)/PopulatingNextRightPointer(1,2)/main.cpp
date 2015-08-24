/*
*	Populating Next Right Pointer I & II
*	Last Modified: 7/14/2015
*/

#include <algorithm>
#include <utility>
#include <stack>
#include "BinaryTree.h"
#include <queue>

class Solution{
public:
	//Populating next right pointer, the tree is complete
	void connect1(TreeLinkNode *root){
		if (!root) return;
		root->next = NULL;
		recursion(root);
	}

	void recursion(TreeLinkNode *node){
		if (!node) return;

		//next of left child is right child
		if (node->left) node->left->next = node->right;

		//next of right child is left child of next
		if (node->right) node->right->next = (node->next == NULL) ? NULL : node->next->left;

		recursion(node->left);
		recursion(node->right);
	}

	//Popluating next right pointer II, incomplete binary tree
	void connect2(TreeLinkNode* root){
		if (!root) return;
		TreeLinkNode *temp = root;
		queue<pair<TreeLinkNode*, int>> q;
		int lv = 0;
		q.push(make_pair(root, 0));
		while (true) {
			lv = q.front().second + 1;
			if (temp->left)
				q.push(make_pair(temp->left, lv));
			if (temp->right)
				q.push(make_pair(temp->right, lv));
			if (q.size() == 1) break;
			pair<TreeLinkNode*, int> node1 = q.front();
			q.pop(); 
			pair<TreeLinkNode*, int> node2 = q.front();
			if (node1.second == node2.second)
				node1.first->next = node2.first;
			else
				node1.first->next = NULL;
			temp = node2.first;
		}
		temp->next = NULL;
	}

	void print(TreeLinkNode *p){
		if (!p) return;
		cout << "The next right node of " << p->val << " is: ";
		if (p->next) cout << p->next->val << endl;
		else cout << "NULL" << endl;
		print(p->left);
		print(p->right);
	}
};

void main(int argc, char* argv[]){
	TreeLinkNode *root = NULL;
	Solution s;
	binaryTree bTree;
	root = bTree.newNode(1);
	root->left = bTree.newNode(2);
	root->right = bTree.newNode(3);
	root->left->left = bTree.newNode(4);
	root->left->right = bTree.newNode(5);
	root->right->left = bTree.newNode(6);
	root->right->right = bTree.newNode(7);

	cout << "Populating next right pointer I: " << endl;
	cout << "The complete binary tree is: " << endl;
	bTree.printTree(root, 4);
	s.connect1(root);
	s.print(root);

	root = NULL;
	root = bTree.newNode(3);
	root->left = bTree.newNode(9);
	root->right = bTree.newNode(20);
	root->right->left = bTree.newNode(15);
	root->right->right = bTree.newNode(7);
	cout << endl << "Populating next right pointer II: " << endl;
	cout << "The incomplete binary tree is: " << endl;
	bTree.printTree(root, 4);
	s.connect2(root);
	s.print(root);
	system("pause");
}