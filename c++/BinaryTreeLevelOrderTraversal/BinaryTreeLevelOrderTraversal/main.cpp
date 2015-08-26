/*
*	Binary Tree Level Order Traversal I & II
*	Last Modified: 7/8/2015
*/

#include "BinaryTree.h"
#include <algorithm>
#include <vector>

class Solution{
public:
	//Binary tree level order traversal I, in top-down order
	vector<vector<int>> levelOrder(TreeNode* root){
		vector<vector<int>> result;
		vector<int> level;
		if (root == NULL) return result;
		int h = height(root);
		for (int i = 1; i <= h; i++)
		{
			result.push_back(traverseTopDown(root, i, level));
			level.clear();
		}
		return result;
	}

	vector<int> traverseTopDown(TreeNode* node, int level, vector<int> value){
		if (node == NULL) return value;
		if (level == 1) {
			value.push_back(node->val);
			return value;
		}
		else{
			value = traverseTopDown(node->left, level - 1, value);
			value = traverseTopDown(node->right, level - 1, value);
			return value;
		}
	}

	//Binary tree level order traversal II, in bottom-up order
	vector<vector<int>> levelOrderBottom(TreeNode* root){
		vector<vector<int>> result;
		vector<int> level;
		if (!root) return result;
		int h = height(root);
		for (int i = h; i >= 1; i--){
			result.push_back(traverseBottomUp(root, level, i));
			level.clear();
		}
		return result;
	}

	vector<int> traverseBottomUp(TreeNode* node, vector<int>& value, int level){
		if (!node) return value;
		if (level == 1){
			value.push_back(node->val);
			return value;
		}
		else{
			value = traverseBottomUp(node->left, value, level - 1);
			value = traverseBottomUp(node->right, value, level - 1);
			return value;
		}
	}

private:
	//Gets the height of the tree
	int height(TreeNode* node){
		if (node == NULL) return 0;
		else{
			int leftHeight = height(node->left);
			int rightHeight = height(node->right);
			int treeHeight = max(leftHeight, rightHeight) + 1;
			return treeHeight;
		}
	}

};

void main(int argc, char *argv[]){
	binaryTree bTree;
	TreeNode *root = NULL;
	root = bTree.insert(root, 3);
	root->left = bTree.insert(root->left, 9);
	root->right = bTree.insert(root->right, 20);
	root->right->left = bTree.insert(root->right->left, 15);
	root->right->right = bTree.insert(root->right->right, 7);

	Solution s;
	vector<vector<int>> result = s.levelOrder(root);
	vector<vector<int>> res = s.levelOrderBottom(root);
	cout << "The level order traversal of the tree (top-down) is: " << endl;
	cout << "[" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << "[";
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j];
			if (j != result[i].size() - 1) cout << ",";
		}
		cout << "]";
		if (i != result.size() - 1) cout << ",";
		cout << endl;
	}
	cout << "]" << endl;

	cout << "The level order traversal of the tree (bottom-up) is: " << endl;
	cout << "[" << endl;
	for (int i = 0; i < res.size(); i++){
		cout << "[";
		for (int j = 0; j < res[i].size(); j++){
			cout << res[i][j];
			if (j != res[i].size() - 1) cout << ",";
		}
		cout << "]";
		if (i != res.size() - 1) cout << ",";
		cout << endl;
	}
	cout << "]" << endl;
	system("pause");
}