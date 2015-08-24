/*
*	Remove Duplicates from Sorted List II
*	Last Modified: 6/10/2015
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	ListNode* deleteDuplicates(ListNode *head){
		if (head == NULL)
			return NULL;
		ListNode *temp = new ListNode(INT_MIN);
		temp->next = head;
		ListNode *previous = head;
		ListNode *start = temp;
		while (previous != NULL){
			bool isDuplicate = false;
			while (previous->next != NULL && previous->val == previous->next->val){
				isDuplicate = true;
				ListNode *current = previous;
				previous = previous->next;
				delete current;
			}
			if (isDuplicate){
				ListNode *current = previous;
				previous = previous->next;
				delete current;
				continue;
			}
			start->next = previous;
			start = start->next;
			previous = previous->next;
		}
		start->next = previous;
		ListNode *current = temp->next;
		delete temp;
		return current;
	}
};

void main(int argc, char *argv[]){
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *print = head;
	ListNode *tail = head;
	ListNode *l2 = new ListNode(1);
	tail->next = l2;
	tail = tail->next;
	ListNode *l3 = new ListNode(1);
	tail->next = l3;
	tail = tail->next;
	ListNode *l4 = new ListNode(2);
	tail->next = l4;
	tail = tail->next;
	ListNode *l5 = new ListNode(3);
	tail->next = l5;
	tail = tail->next;

	cout << "The original linked list is: ";
	while (print != NULL){
		cout << print->val;
		print = print->next;
		if (print != NULL)
			cout << "->";
	}
	cout << endl;

	ListNode *result = s.deleteDuplicates(head);
	cout << "The current linked list is: ";
	while (result != NULL){
		cout << result->val;
		result = result->next;
		if (result != NULL)
			cout << "->";
	}
	cout << endl;
	system("pause");
}