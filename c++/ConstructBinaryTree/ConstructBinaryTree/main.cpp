/*
*	Construct Binary Tree (Preorder/Inorder) & (Inorder/Postorder) 
*	Last Modified: 7/9/2015
*/

#include "BinaryTree.h"
#include <map>
#include <vector>

class Solution{
public:
	//Construct binary tree from preorder and inorder
	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder){
		return buildTreeInorderPreorder(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}

	TreeNode* buildTreeInorderPreorder(vector<int>& preorder, int startPre, int endPre, vector<int>& inorder, int startIn, int endIn){
		if (startPre >= endPre || startIn >= endIn) return NULL;
		TreeNode *root = new TreeNode(preorder[startPre]);
		int i = startIn;
		for (; i < endIn; i++){
			if (inorder[i] == preorder[startPre]) break;
		}
		root->left = buildTreeInorderPreorder(preorder, startPre + 1, startPre + 1 + i - startIn, inorder, startIn, i);
		root->right = buildTreeInorderPreorder(preorder, startPre + 1 + i - startIn, endPre, inorder, i + 1, endIn);
		return root;
	}

	//Construct binary tree from inorder and postorder
	TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder){
		return buildTreeInorderPostorder(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}

	TreeNode* buildTreeInorderPostorder(vector<int>& inorder, int startIn, int endIn, vector<int>& postorder, int startPost, int endPost){
		if (startIn >= endIn || startPost >= endPost) return NULL;
		TreeNode *root = new TreeNode(postorder[endPost - 1]);
		int i = startIn;
		for (; i < endIn; i++){
			if (inorder[i] == postorder[endPost - 1]) break;
		}
		root->left = buildTreeInorderPostorder(inorder, startIn, i, postorder, startPost, startPost + i - startIn);
		root->right = buildTreeInorderPostorder(inorder, i + 1, endIn, postorder, startPost + i - startIn, endPost - 1);
		return root;
	}
};

void main(int argc, char* argv[]){
	vector<int> preorder = { 7, 10, 4, 3, 1, 2, 8, 11 };
	vector<int> inorder = { 4, 10, 3, 1, 7, 2, 8, 11 };
	vector<int> postorder = { 4, 1, 3, 10, 11, 8, 2, 7 };
	int m = preorder.size();
	cout << "The preorder traversal is: ";
	for (int i = 0; i < m; i++)
	{
		cout << preorder[i];
		if (i != m - 1) cout << ",";
	}
	cout << endl;
	cout << "The inorder traversal is: ";
	for (int i = 0; i < m; i++)
	{
		cout << inorder[i];
		if (i != m - 1) cout << ",";
	}
	cout << endl;
	cout << "The postorder traversal is: ";
	for (int i = 0; i < m; i++)
	{
		cout << postorder[i];
		if (i != m - 1) cout << ",";
	}
	cout << endl;
	binaryTree bTree;
	Solution s;
	TreeNode *root1 = s.buildTree1(preorder, inorder);
	cout << "The tree constructed from preorder + inorder traversal is: " << endl;
	bTree.printTree(root1, 4);
	cout << "The tree constructed from inorder + postorder traversal is: " << endl;
	TreeNode *root2 = s.buildTree2(inorder, postorder);
	bTree.printTree(root2, 4);
	system("pause");
}