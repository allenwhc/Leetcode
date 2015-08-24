#include <iostream>
#include <iomanip>
using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){}
};

class binaryTree{
public:
	TreeLinkNode* insert(TreeLinkNode* node, int data){
		if (node == NULL) return newNode(data);
	}

	void printTree(TreeLinkNode *root, int indent){
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
	TreeLinkNode* newNode(int data){
		TreeLinkNode *node = new TreeLinkNode(data);
		node->left = NULL;
		node->right = NULL;
		return node;
	}

};