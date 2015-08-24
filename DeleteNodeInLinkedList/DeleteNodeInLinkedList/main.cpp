/*
*	Delete Node in A Linked List
*	Last Modified: 7/16/2015
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	void deleteNode(ListNode *node){
		if (!node || !node->next) return;
		ListNode *temp = new ListNode(-1);
		temp = node->next;
		node->val = temp->val;
		node->next = temp->next;
		delete temp;
	}
};

void main(int argc, char *argv[]){
	ListNode *head = new ListNode(1);
	ListNode *tail = head;
	ListNode *print = head;
	ListNode *n1 = new ListNode(2);
	tail->next = n1;
	tail = tail->next;
	ListNode *n2 = new ListNode(3);
	tail->next = n2;
	tail = tail->next;
	ListNode *n3 = new ListNode(4);
	tail->next = n3;
	tail = tail->next;

	Solution s;
	cout << "The original list is: ";
	while (print){
		cout << print->val;
		print = print->next;
		if (print) cout << "->";
	}
	cout << endl;
	ListNode *node = n2;

	cout << "The list after deleting " << node->val << " is: ";
	s.deleteNode(node);
	while (head){
		cout << head->val;
		head = head->next;
		if (head) cout << "->";
	}
	cout << endl;
	system("pause");
}