/*
*	Minimum Depth of Binary Tree
*	Last Modified: 6/23/2015
*/

#include "BinaryTree.h"
#include <algorithm>
#include <vector>

class Solution{
public:
	int minDepth(TreeNode* root){
		if (root == NULL) return 0;
		if (root->left == NULL && root->right == NULL) return 0;
		int nearest = INT_MAX;
		vector<int> distance;
		getAllPathDistance(root, distance, 1);
		while (!distance.empty()){
			nearest = min(nearest, distance.back());
			distance.pop_back();
		}
		return nearest;
	}

	void getAllPathDistance(TreeNode* node, vector<int>& distance, int count){
		if (node == NULL) return;
		if (node->left == NULL && node->right == NULL){
			distance.push_back(count);
		}
		else{
			count++;
			getAllPathDistance(node->left, distance, count);
			getAllPathDistance(node->right, distance, count);
		}
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	Solution s;
	TreeNode *root = NULL;
	root = bTree.newNode(1);
	root->left = bTree.newNode(2);
	root->right = bTree.newNode(3);
	root->right->left = bTree.newNode(5);
	//root->right->right = bTree.newNode(7);

	int min = s.minDepth(root);
	cout << "The minimum depth of the given binary tree is: " << min << endl;
	system("pause");
}