/*
*	Lowest Common Ancestor in Binary (Search) Tree
*	Last Modified: 7/23/2015
*	Hint:
	I.  BT:
		****Can't compare the value of nodes, since there might be duplicate values
		Check the current node: 
			If current node=p, or q, return current node
			Set leftLCA=LCA(node->left,p,q), rightLCA=LCA(node->right,p,q)
			If both leftLCA and rightLCA are not NULL ptr, return root
			Else return the pointer that is not empty in leftLCA and rightLCA

	II. BST:
		Check the value of current node: 
			If it is less than both of target values, traverse the right subtree;
			Else if it is greater than both of target values, traverse the left subtree;
			Else return the current node
*/

#include "BinaryTree.h"
#include <vector>

class Solution {
public:
	//LCA for Binary Tree
	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return NULL;
		if (root == p || root == q) return root;
		TreeNode *leftLCA = lowestCommonAncestor1(root->left, p, q);
		TreeNode *rightLCA = lowestCommonAncestor1(root->right, p, q);
		if (leftLCA && rightLCA) return root;
		return leftLCA ? leftLCA : rightLCA;
	}

	// LCA for Binary Search Tree
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return NULL;
		if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor2(root->right, p, q);
		else if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor2(root->left, p, q);
		else return root;
	}
};

void main(int argc, char *argv[]){
	TreeNode *root1 = NULL;
	binaryTree bTree;
	root1 = bTree.newNode(37);
	root1->left = bTree.newNode(-34);
	root1->right = bTree.newNode(-48);
	root1->left->right = bTree.newNode(-100);
	root1->right->left = bTree.newNode(-100);
	root1->right->right = bTree.newNode(48);
	root1->right->left->left = bTree.newNode(-54);
	root1->right->right->left = bTree.newNode(-71);
	root1->right->right->right = bTree.newNode(-22);
	cout << "The binary tree is: " << endl;
	bTree.printPretty(root1, 1, 0, cout);

	Solution s;
	TreeNode *p = root1->right->left;
	TreeNode *q = root1->right->right->left;
	TreeNode *LCABT = s.lowestCommonAncestor1(root1, p, q);
	cout << "The lowest common ancestor of " << p->val << " and " << q->val << " is " << LCABT->val << endl;

	TreeNode *root2 = NULL;
	root2 = bTree.newNode(6);
	root2->left = bTree.newNode(2);
	root2->right = bTree.newNode(8);
	root2->left->left = bTree.newNode(0);
	root2->left->right = bTree.newNode(4);
	root2->right->left = bTree.newNode(7);
	root2->right->right = bTree.newNode(9);
	root2->left->right->left = bTree.newNode(3);
	root2->left->right->right = bTree.newNode(5);
	cout << endl << "The binary search  tree is: " << endl;
	bTree.printPretty(root2, 1, 0, cout);
	TreeNode *p2 = root2->left->left;
	TreeNode *q2 = root2->right->right;
	TreeNode *LCABST = s.lowestCommonAncestor2(root2, p2, q2);
	cout << "The lowest common ancestor of " << p2->val << " and " << q2->val << " is " << LCABST->val << endl;
	system("pause");
}