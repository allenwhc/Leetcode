/*
*	Sum Root to Leaf Numbers
*	Last Modified: 6/23/2015
*/

#include "BinaryTree.h"
#include <vector>

class Solution{
public:
	int sumNumbers(TreeNode *root){
		if (root == NULL) return 0;
		int sum = 0;
		getPath(root, 0, sum);
		return sum;
	}

	//Gets number from all paths
	void getPath(TreeNode* node, int level, int &sum){
		if (node->left == NULL && node->right == NULL){
			level = level * 10 + node->val;
			sum += level;
		}
		else{
			level = level * 10 + node->val;
			if (node->left != NULL) getPath(node->left, level, sum);
			if (node->right != NULL) getPath(node->right, level, sum);
		}
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	TreeNode *root = NULL;
	root = bTree.insert(root, 1);
	root->left = bTree.insert(root->left, 2);
	root->right = bTree.insert(root->right, 3);
	root->left->left = bTree.insert(root->left->left, 5);
	root->right->left = bTree.insert(root->right->left, 3);
	root->right->right = bTree.insert(root->right->right, 7);

	Solution s;
	int sum = s.sumNumbers(root);
	cout << "The sum of all root-to-leaf numbers is: " << sum << endl;
	system("pause");
}