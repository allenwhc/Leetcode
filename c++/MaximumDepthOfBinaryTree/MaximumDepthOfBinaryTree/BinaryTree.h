#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

class binaryTree{
public:
	TreeNode* newNode(int num){
		TreeNode *node = new TreeNode;
		node->val = num;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	TreeNode* insert(TreeNode *node, int num){
		if (node == NULL) return newNode(num);
		else{
			if (num <= node->val) node->left = insert(node->left, num);
			else node->right = insert(node->right, num);
		}
	}
};
