/*
*	Binary Tree Right Side View
*	Last Modified: 7/3/2015
*/

#include "BinaryTree.h"
#include <queue>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> rightSideView(TreeNode* root){
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (q.size() > 0){
			int size = q.size();
			for (int i = 0; i < size; i++){
				TreeNode *top = q.front();
				q.pop();
				if (i == 0) res.push_back(top->val);
				if (top->right) q.push(top->right);
				if (top->left) q.push(top->left);
			}
		}
		return res;
	}
};

void main(int argc, char* argv[]){
	TreeNode *root = NULL;
	binaryTree bTree;
	Solution s;
	root = bTree.newNode(1);
	root->left = bTree.newNode(2);
	root->right = bTree.newNode(3);
	root->left->right = bTree.newNode(5);
	root->right->right = bTree.newNode(4);
	cout << "The binary tree is: " << endl;
	bTree.printTree(root, 1);
	vector<int> rightSide = s.rightSideView(root);
	cout << "The right side view of the above binary tree is: ";
	for (int i = 0; i < rightSide.size(); i++)
		cout << rightSide[i] << " ";
	cout << endl;
	system("pause");
}