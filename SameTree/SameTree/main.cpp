/*
*	Same Tree
*	Last Modified: 6/22/2015
*/

#include "BinaryTree.h"

class Solution{
public:
	bool isSameTree(TreeNode *p, TreeNode *q){
		if (p == NULL && q == NULL) return true;
		else if (p != NULL && q != NULL){
			if (p->val != q->val) return false;
			if (!isSameTree(p->left, q->left)) return false;
			if (!isSameTree(p->right, q->right)) return false;
			return true;
		}
		else return false;
	}
};

void main(int argc, char *argv[]){
	binaryTree bTree;
	TreeNode *root1 = NULL;
	root1 = bTree.insert(root1, 3);
	root1->left = bTree.insert(root1->left, 4);
	root1->right = bTree.insert(root1->right, 7);
	root1->left->left = bTree.insert(root1->left->left, 10);
	
	TreeNode *root2 = NULL;
	root2 = bTree.insert(root2, 3);
	root2->left = bTree.insert(root2->left, 4);
	root2->right = bTree.insert(root2->right, 7);
	root2->left->right = bTree.insert(root2->left->right, 10);

	Solution s;
	bool isSame = s.isSameTree(root1, root2);
	if (isSame) cout << "Same tree!" << endl;
	else cout << "Not same tree!" << endl;
	system("pause");
}