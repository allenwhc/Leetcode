#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class binaryTree{
public:
	TreeNode* insert(TreeNode* node, int data){
		if (node == NULL) return newNode(data);
	}

	void printTree(TreeNode* node){
		if (node == NULL) return;
		printTree(node->left);
		cout << node->val << ",";
		printTree(node->right);
	}
	TreeNode* newNode(int data){
		TreeNode *node = new TreeNode(data);
		node->left = NULL;
		node->right = NULL;
		return node;
	}

};