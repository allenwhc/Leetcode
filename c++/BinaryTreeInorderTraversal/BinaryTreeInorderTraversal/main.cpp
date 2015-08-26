/*
*	Binary Tree Inorder Traversal
*	Last Modified: 7/12/2015
*/

#include "BinaryTree.h"
#include <vector>

class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> result;
		traverse(root, result);
		return result;
	}

	void traverse(TreeNode* node, vector<int>& values){
		if (!node) return;
		if (node->left) traverse(node->left, values);
		values.push_back(node->val);
		if (node->right) traverse(node->right, values);
	}
};

void main(int argc, char* atgv[]){
	Solution s;
	binaryTree bTree;
	TreeNode *root = NULL;
	root = bTree.newNode(1);
	root->left = bTree.newNode(2);
	root->right = bTree.newNode(3);
	root->left->left = bTree.newNode(4);
	root->left->right = bTree.newNode(5);
	root->right->right = bTree.newNode(6);
	cout << "The binary tree is: " << endl;
	bTree.printTree(root, 4);
	vector<int> res = s.inorderTraversal(root);
	cout << "The inorder traversal is: ";
	for (int i = 0; i < res.size(); i++){
		cout << res[i];
		if (i != res.size() - 1) cout << ",";
	}
	cout << endl;
	system("pause");
}