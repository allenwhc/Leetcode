#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
	int res = 0; 
	void getSum(TreeNode *root, int curr_sum){
		if(!root) return;
		cout << curr_sum << endl;
		if(curr_sum == 0){++res; return;}
		//if(root->left){
			getSum(root->left, curr_sum - root->val);
		//}
		//if(root->right){
			getSum(root->right, curr_sum - root->val);
		//x}
	}
public:
	int pathSum(TreeNode* root, int sum){
		getSum(root, sum);
		return res;
	}
};

void printTree(TreeNode* root, string indent){
	if(root){
		printTree(root->right, indent + "   ");
		cout << indent << root->val << endl;
		printTree(root->left, indent + "   ");
	}
}

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);
	printTree(root, "");
	Solution sol;
	cout << sol.pathSum(root,22) << endl;
	return 0;
}