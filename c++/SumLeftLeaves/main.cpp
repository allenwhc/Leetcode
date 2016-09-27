#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int sumOfLeftLeaves(TreeNode* root){
	int res = 0;
	if(root){
		if(root->left && !root->left->left && !root->left->right)
			res += root->left->val;
		else res += sumOfLeftLeaves(root->left);
		res += sumOfLeftLeaves(root->right);
	}
	return res;
}

void printTree(TreeNode* root, int indent=0){
	if(!root) return;
	printTree(root->right, indent+4);
	if(indent){cout << setw(indent) << ' ';}
	cout << root->val << endl;
	printTree(root->left, indent+4);
}

int main(int argc, char const *argv[])
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	root->left->right = new TreeNode(10);
	root->left->right->left = new TreeNode(4);
	printTree(root);
	cout << sumOfLeftLeaves(root) << endl;
	return 0;
}