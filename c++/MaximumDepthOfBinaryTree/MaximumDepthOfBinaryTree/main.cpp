/*
*	Maximum Depth of A Binary Tree
*	Last Modified: 6/15/2015
*/

#include <algorithm>
#include "BinaryTree.h"

//struct TreeNode{
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL){}
//};

class Solution{
public:
	int maxDepth(TreeNode *root){
		if (root == NULL) return 0;
		int leftMax = maxDepth(root->left);
		int rightMax = maxDepth(root->right);
		return max(leftMax, rightMax) + 1;
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	Solution s;
	TreeNode *root = new TreeNode;
	root->val = 5;
	TreeNode *node1_left = bTree.insert(root->left, 3);
	TreeNode *node1_right = bTree.insert(root->right, 8);
	int depth = s.maxDepth(root);
	cout << "The maximum depth of the tree is: " << depth << endl;
	system("pause");
}