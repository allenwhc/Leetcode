/*
*	Binary Tree Zigzag Level Order Traversal
*	Last Modified: 7/22/2015
*/

#include <algorithm>
#include "BinaryTree.h"
#include <vector>

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> allLevels;
		vector<int> level;
		if (!root) return allLevels;
		int h = treeHeight(root);
		bool isLeftToRight = true;	//Start from left to right
		for (int i = 1; i <= h; i++){
			vector<int> res = traverseLevelOrder(level, root, i, isLeftToRight);
			allLevels.push_back(res);
			level.clear();
			isLeftToRight = !isLeftToRight;		//Change direction
		}
		return allLevels;
	}

	vector<int> traverseLevelOrder(vector<int>& level, TreeNode* node, int step, bool isLeftToRight){
		if (!node) return level;
		if (step == 1){
			level.push_back(node->val);
			return level;
		}
		else if (step > 1){
			if (isLeftToRight){
				level = traverseLevelOrder(level, node->left, step - 1, isLeftToRight);
				level = traverseLevelOrder(level, node->right, step - 1, isLeftToRight);
			}
			else{
				level = traverseLevelOrder(level, node->right, step - 1, isLeftToRight);
				level = traverseLevelOrder(level, node->left, step - 1, isLeftToRight);
			}
			return level;
		}
	}

	int treeHeight(TreeNode *root){
		if (!root) return 0;
		int lh = treeHeight(root->left); 
		int rh = treeHeight(root->right);
		return max(lh, rh) + 1;
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	TreeNode *root = NULL;
	root = bTree.newNode(2);
	root->left = bTree.newNode(7);
	root->right = bTree.newNode(5);
	root->left->left = bTree.newNode(2);
	root->left->right = bTree.newNode(6);
	root->right->right = bTree.newNode(9);
	root->left->right->left = bTree.newNode(5);
	root->left->right->right = bTree.newNode(11);
	root->right->right->left = bTree.newNode(4);
	cout << "The binary tree is: " << endl;
	bTree.printPretty(root, 1, 0, cout);
	Solution s;
	vector<vector<int>> zigzag = s.zigzagLevelOrder(root);
	cout << "The zigzag level order traversal is: " << endl;
	for (vector<int> zz : zigzag){
		for (int z : zz)
			cout << z << " ";
		cout << endl;
	}
	system("pause");
}