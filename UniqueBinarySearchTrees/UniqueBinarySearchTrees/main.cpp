/*
*	Unique Binary Search Tree I & II
*	Description: Implementation of Catalan Number
*				 Cn=sum(Ci*Cn-i), i=0,1,...,n; n=1,2,...
*	Last Modified: 7/15/2015
*/

#include "BinaryTree.h"
#include <vector>

class Solution{
public:
	//Unique Binary Search Tree I, return total number of unique BSTs
	int numTrees(int n){
		vector<int> count(n + 1, 0);
			count[0] = 1;
			count[1] = 1;
			for (int i = 2; i <= n; i++)
			{
				for (int j = 0; j<i; j++)
				{
					count[i] += count[j] * count[i - j - 1];
				}
			}
			return count[n];
	}

	//Unique binary search tree II, return all unique BSTs
	vector<TreeNode*> generateTrees(int n){
		return getTrees(1, n);
	}

	vector<TreeNode*> getTrees(int minimum, int maximum){
		vector<TreeNode*> res;
		if (minimum > maximum){
			res.push_back(NULL);
			return res;
		}
		for (int i = minimum; i <= maximum; i++){
			vector<TreeNode*> leftTree = getTrees(minimum, i - 1);
			vector<TreeNode*> rightTree = getTrees(i + 1, maximum); 
			for (int j = 0; j < leftTree.size(); j++){
				for (int k = 0; k < rightTree.size(); k++){
					TreeNode *root = new TreeNode(i);
					root->left = leftTree[j];
					root->right = rightTree[k];
					res.push_back(root);
				}
			}
		}
		return res;
	}
};

void main(int argc, char *argv[]){
	int num = 0;
	int n;
	Solution s;
	binaryTree bTree;
	cout << "Select the number of values from 1 to n: ";
	cin >> n;
	num = s.numTrees(n);
	cout << "The number of BST's is: " << num << endl;
	vector<TreeNode*> res = s.generateTrees(n);
	for (int i = 0; i < res.size(); i++){
		cout << "BST " << i + 1 << ": " << endl;
		bTree.printTree(res[i], 4);
		cout << endl;
	}
	system("pause");
}