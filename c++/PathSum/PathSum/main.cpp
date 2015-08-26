/*
*	Path Sum I & II
*	Last Modified: 6/29/2015
*/

#include "BinaryTree.h"
#include <vector>

class Solution{
public:
	//Path Sum I, check if there is a root-to-leaf path whose sum of the val equals to a value
	bool hasPathSum(TreeNode* root, int sum){
		return checkSum(root, 0, sum);
	}

	bool checkSum(TreeNode* node, int sum, int& restSum){
		if (node == NULL) return false;
		sum = sum + node->val;
		if (node->left == NULL && node->right == NULL){
			if (sum == restSum) return true;
			else return false;
		}
		return checkSum(node->left, sum, restSum) || checkSum(node->right, sum, restSum);
	}

	//Path Sum II, get all the paths qualifying conditions in Path Sum I
	vector<vector<int>> pathSum(TreeNode* root, int sum){
		vector<vector<int>> allSol;
		vector<int> sol;
		if (root == NULL) return allSol;
		sol.push_back(root->val);
		sum = sum - root->val;
		getAllPaths(allSol, sol, root, sum);
		return allSol;
	}

	void getAllPaths(vector<vector<int>>& allSol, vector<int>& sol, TreeNode* node, int sum){
		if (node->left == NULL && node->right == NULL && sum == 0){
			vector<int> temp = sol;
			allSol.push_back(temp);
		}
		if (node->left){
			sol.push_back(node->left->val);
			getAllPaths(allSol, sol, node->left, sum - node->left->val);
			sol.pop_back();
		}
		if (node->right){
			sol.push_back(node->right->val);
			getAllPaths(allSol, sol, node->right, sum - node->right->val);
			sol.pop_back();
		}
	}
};

void main(int argc, char* argv[]){
	binaryTree bTree;
	Solution s;
	TreeNode *root = NULL;
	/*root = bTree.newNode(1);
	root->left = bTree.newNode(2);*/
	root = bTree.newNode(5);
	root->left = bTree.newNode(4);
	root->right = bTree.newNode(8);
	root->left->left = bTree.newNode(11);
	root->right->left = bTree.newNode(13);
	root->right->right = bTree.newNode(4);
	root->left->left->left = bTree.newNode(7);
	root->left->left->right = bTree.newNode(2);
	root->right->right->left = bTree.newNode(5);
	root->right->right->right = bTree.newNode(1);

	int sum = 22;
	bool hasSum = s.hasPathSum(root, sum);
	if (hasSum) cout << "There's a path" << endl;
	else cout << "There isn't a path" << endl;

	vector<vector<int>> path = s.pathSum(root, sum);
	cout << "The paths along which the sum is " << sum << " are: " << endl;
	cout << "[" << endl;
	for (int i = 0; i < path.size(); i++){
		cout << "[";
		for (int j = 0; j < path[i].size(); j++){
			cout << path[i][j];
			if (j != path[i].size() - 1) cout << ",";
		}
		cout << "]";
		if (i != path.size() - 1) cout << "," << endl;
	}
	cout << endl << "]" << endl;
	system("pause");
}