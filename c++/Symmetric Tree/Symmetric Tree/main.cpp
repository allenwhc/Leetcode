/*
*	Symmetric Tree
*	Last Modified: 6/22/2015
*/

#include "BinaryTree.h"
#include <vector>

class Solution{
public:
	//Recursive solution
	bool isSymmetric(TreeNode* root){
		if (root == NULL) return true;
		return recursion(root->left, root->right);
	}
	bool recursion(TreeNode* left, TreeNode* right){
		if (left == NULL || right == NULL) return left == NULL&&right == NULL;
		return left->val == right->val && recursion(left->left, right->right) && recursion(left->right, right->left);
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	TreeNode *root1 = NULL;
	root1 = bTree.insert(root1, 1);
	root1->left = bTree.insert(root1->left, 2);
	root1->right = bTree.insert(root1->right, 2);
	root1->left->left = bTree.insert(root1->left->left, 3);
	root1->left->right = bTree.insert(root1->left->right, 4);
	root1->right->left = bTree.insert(root1->right->left, 4);
	root1->right->right = bTree.insert(root1->right->right, 3);

	TreeNode *root2 = NULL;
	root2 = bTree.insert(root2, 1);
	root2->left = bTree.insert(root2->left, 2);
	root2->right = bTree.insert(root2->right, 2);
	root2->left->right = bTree.insert(root2->left->right, 3);
	root2->right->right = bTree.insert(root2->right->right, 3);

	Solution s;
	vector<bool> isSym;
	isSym.push_back(s.isSymmetric(root2));
	isSym.push_back(s.isSymmetric(root1));
	while (!isSym.empty()){
		if (isSym.back()) cout << "Symmetric!" << endl;
		else cout << "Not symmetric!" << endl;
		isSym.pop_back();
	}
	system("pause");
}