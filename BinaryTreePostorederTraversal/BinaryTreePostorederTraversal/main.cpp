/*
*	Binary Tree Postorder Traversal
*	Last Modified: 7/12/2015
*/

#include "BinaryTree.h"
#include <vector>

class Solution{
public:
	vector<int> postorderTraversal(TreeNode* root){
		vector<int> result;
		traverse(root, result);
		return result;
	}

	void traverse(TreeNode* node, vector<int>& values){
		if (!node) return;
		if (node->left) traverse(node->left, values);
		if (node->right) traverse(node->right, values);
		values.push_back(node->val);
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
	vector<int> res = s.postorderTraversal(root);
	cout << "The postorder traversal is: ";
	for (int i = 0; i < res.size(); i++){
		cout << res[i];
		if (i != res.size() - 1) cout << ",";
	}
	cout << endl;
	system("pause");
}