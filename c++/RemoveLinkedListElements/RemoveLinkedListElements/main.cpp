/*
*	Remove Linked List Elements
*	Last Modified: 6/19/2015
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
	ListNode* removeElements(ListNode *head, int val){
		ListNode *fakeHead = new ListNode(-1);
		fakeHead->next = head;
		ListNode *p = fakeHead;
		while (p->next != NULL){
			if (p->next->val == val){
				ListNode *current = p->next;
				p->next = current->next;
			}
			else{
				p = p->next;
			}
		}
		ListNode *temp = fakeHead;
		delete fakeHead;
		return temp->next;
	}
};

void main(int argc, char *argv[]){
	ListNode *head = new ListNode(1);
	ListNode *print = head;
	ListNode *tail = head;
	ListNode *node1 = new ListNode(1);
	tail->next = node1;
	tail = tail->next;
	ListNode *node2 = new ListNode(1);
	tail->next = node2;
	tail = tail->next;
	/*ListNode *node3 = new ListNode(3);
	tail->next = node3;
	tail = tail->next;
	ListNode *node4 = new ListNode(4);
	tail->next = node4;
	tail = tail->next;
	ListNode *node5 = new ListNode(5);
	tail->next = node5;
	tail = tail->next;
	ListNode *node6 = new ListNode(6);
	tail->next = node6;
	tail = tail->next;*/

	cout << "The original list is: ";
	while (print != NULL){
		cout << print->val;
		print = print->next;
		if (print != NULL) cout << "->";
	}
	cout << endl;
	Solution s;
	int val = 1;
	ListNode *remove = s.removeElements(head, val);
	cout << "The linkeds list after removing " << val << " is: ";
	while (remove != NULL){
		cout << remove->val;
		remove = remove->next;
		if (remove != NULL) cout << "->";
	}
	cout << endl;
	system("pause");
}