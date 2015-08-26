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

	void printTree(TreeNode *root, int indent){
		if (root){
			if (root->right) printTree(root->right, indent + 4);
			if (indent) cout << setw(indent);
			if (root->right) cout << "/\n" << setw(indent) << ' ';
			cout << root->val << endl;
			if (root->left){
				cout << setw(indent) << ' ' << "\\\n";
				printTree(root->left, indent + 4);
			}
		}
	}
	TreeNode* newNode(int data){
		TreeNode *node = new TreeNode(data);
		node->left = NULL;
		node->right = NULL;
		return node;
	}

};