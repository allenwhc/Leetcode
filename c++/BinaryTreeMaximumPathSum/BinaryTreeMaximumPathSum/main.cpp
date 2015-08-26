/*
*	Binary Tree Maximum Path Sum
*	Last Modified: 7/17/2015
*/

#include <algorithm>
#include "BinaryTree.h"
#include <vector>

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		vector<int> maximum;
		maximum.push_back(INT_MIN);
		getMax(root, maximum);
		return maximum.back();
	}
	
	int getMax(TreeNode* root, vector<int>& maximum){
		if (!root) return 0;
		int leftMax = getMax(root->left, maximum);	//Left subtree
		int rightMax = getMax(root->right, maximum);	//Right subtree
		int arch = leftMax + rightMax + root->val;	//Pass through itself
		int self = max(root->val, max(leftMax, rightMax) + root->val);	//Count the node itself
		int x = maximum.back();
		maximum.pop_back();
		maximum.push_back(max(x, max(self, arch)));
		return self;
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	TreeNode *root = NULL;
	Solution s;
	root = bTree.newNode(-15);
	root->left = bTree.newNode(5);
	root->right = bTree.newNode(6);
	root->left->left = bTree.newNode(-8);
	root->left->right = bTree.newNode(1);
	root->left->left->left = bTree.newNode(2);
	root->left->left->right = bTree.newNode(6);
	root->right->left = bTree.newNode(3);
	root->right->right = bTree.newNode(9);
	root->right->right->right = bTree.newNode(0);

	cout << "The Binary Tree is: " << endl;
	bTree.printPretty(root, 1, 0, cout);
	cout << endl << "The maximum path sum is: " << s.maxPathSum(root) << endl;
	system("pause");
}