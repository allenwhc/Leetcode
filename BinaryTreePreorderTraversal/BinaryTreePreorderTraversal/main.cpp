/*
*	Binary Tree Preoreder Traversal
*	Last Modified: 6/23/2015
*/

#include "BinaryTree.h"
#include <vector>
#include <stack>

class Solution{
public:
	vector<int> preorderTraversal(TreeNode* root){
		//Recursive solution
		vector<int> empty;
		if (root == NULL) return empty;
		vector<int> output;
		output.push_back(root->val);
		output = preorderTraversal(root->left);
		output = preorderTraversal(root->right);
		return output;
		

		//Iterative solution
		/*stack<TreeNode*> myStack;
		vector<int> output;
		if(root == NULL) return output;
		while (myStack.size() > 0 || root != NULL){
			if (root != NULL){
				output.push_back(root->val);
				if (root->right != NULL) myStack.push(root->right);
				root = root->left;
			}
			else{
				root = myStack.top();
				myStack.pop();
			}
		}*/
		
	} 
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	TreeNode *root = NULL;
	root = bTree.insert(root, 1);
	root->left = bTree.insert(root->left, 4);
	root->right = bTree.insert(root->right, 2);
	root->left->left = bTree.insert(root->left->left, 7);
	root->left->right = bTree.insert(root->left->right, 5);
	root->right->right = bTree.insert(root->right->right, 3);
	

	Solution s;
	vector<int> preorder = s.preorderTraversal(root);
	cout << "The preorder traversal of the tree is: [";
	for (int i = 0; i < preorder.size(); i++){
		cout << preorder[i];
		if (i != preorder.size() - 1) cout << ",";
	}
	cout << "]" << endl;
	system("pause");
}