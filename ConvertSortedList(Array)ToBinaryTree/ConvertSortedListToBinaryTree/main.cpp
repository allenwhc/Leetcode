/*
*	Convert Sorted List/Array to Binary Tree
*	Last Modified: 7/3/2015
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	//Converts the sorted list to BST
	TreeNode* sortedListToBST(ListNode* head){
		if (!head) return NULL;
		int len = 0;
		ListNode *p1 = head;
		while (p1){
			len++;
			p1 = p1->next;
		}
		return convertSortedList(head, 0, len - 1);
	}

	//Recursively makes the middle of the partial list the parent node
	TreeNode* convertSortedList(ListNode*& node, int start, int end){
		if (start > end) return NULL;
		int middle = (start + end) / 2;

		//Creates the left subtree
		TreeNode *leftTree = convertSortedList(node, start, middle - 1);

		//Adds root node to the tree
		TreeNode *root = newNode(node->val);
		root->left = leftTree;
		
		//Moves the list pointer
		node = node->next;

		//Creates the right tree
		root->right = convertSortedList(node, middle + 1, end);

		return root;
	}

	//Converts the sorted array to BST
	TreeNode* sortedArrayToBST(vector<int>& nums){
		int n = nums.size();
		return convertSortedArray(nums, 0, n - 1);
	}

	TreeNode* convertSortedArray(vector<int>& nums, int start, int end){
		if (start > end) return NULL;
		int middle = (start + end) / 2;
		TreeNode *leftTree = convertSortedArray(nums, start, middle - 1);
		TreeNode *root = newNode(nums[middle]);
		root->left = leftTree;

		root->right = convertSortedArray(nums, middle + 1, end);
		return root;
	}

private:
	//Creates new tree nodes
	TreeNode* newNode(int data){
		TreeNode *root = new TreeNode(data);
		return root;
	}
};

void printTree(TreeNode *root, int indent){
	if (root){
		if (root->right) printTree(root->right, indent + 4);
		if (indent) cout << setw(indent);
		if (root->right) cout << "/\n" << setw(indent) << ' ';
		cout << root->val << endl;
		if (root->left){
			cout << setw(indent) << ' ' << "\\\n";
			printTree(root->left, indent + 4);
		}
	}
}

void main(int argc, char* argv[]){
	ListNode *head = new ListNode(1);
	ListNode *print = head;
	ListNode *tail = head;
	ListNode *n1 = new ListNode(2);
	tail->next = n1;
	tail = tail->next; 
	ListNode *n2 = new ListNode(3);
	tail->next = n2;
	tail = tail->next;
	ListNode *n3 = new ListNode(4);
	tail->next = n3;
	tail = tail->next;
	ListNode *n4 = new ListNode(5);
	tail->next = n4;
	tail = tail->next;
	ListNode *n5 = new ListNode(6);
	tail->next = n5;
	tail = tail->next;
	ListNode *n6 = new ListNode(7);
	tail->next = n6;
	tail = tail->next;

	
	cout << "The sorted linked list is: ";
	while (print){
		cout << print->val;
		print = print->next;
		if (print) cout << "->";
	}
	cout << endl;

	Solution s;
	TreeNode *root = s.sortedListToBST(head);
	cout << "The height-balanced binary search tree is: " << endl;
	printTree(root, 1);

	vector<int> nums = { 2, 5, 7, 9, 11, 13, 17 };
	cout << endl << "The sorted array is: ";
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	TreeNode *root2 = s.sortedArrayToBST(nums); 
	cout << "The height-balanced binary search tree is: " << endl;
	printTree(root2, 1);
	system("pause");
}