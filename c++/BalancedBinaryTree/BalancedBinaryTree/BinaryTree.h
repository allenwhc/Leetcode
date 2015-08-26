#include <iostream>
#include <iomanip>
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

	void printTree(TreeNode* node, int indent){
		if (node != NULL){
			if (node->left) printTree(node->left, indent + 4);
			if (node->right) printTree(node->right, indent + 4);
			if (indent){
				cout << setw(indent) << ' ';
			}
			cout << node->val << endl;
		}
	}
	TreeNode* newNode(int data){
		TreeNode *node = new TreeNode(data);
		node->left = NULL;
		node->right = NULL;
		return node;
	}

};