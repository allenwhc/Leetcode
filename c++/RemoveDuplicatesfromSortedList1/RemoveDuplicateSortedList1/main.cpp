/*
*	Remove Duplicates from Sorted List I
*	Last Modified: 6/2/2015
*/

#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
};

class Solution{
public:
	ListNode* deleteDuplicates(ListNode* head){
		if (head == NULL || head->next == NULL) 
			return head;	//If the list is empty, then return NULL
		else{
			ListNode *previous, *current;
			previous = head;
			current = head->next;
			while (current != NULL){
				if (current->val == previous->val)
				{
					previous->next = current->next;
					current = current->next;
				}
				else{
					previous = previous->next;
					current = current->next;
				}
			}
			return head;
		}
	}
};

void main(int argc, char *argv[]){
	ListNode *head = new ListNode;
	head->val = 1;
	ListNode *temp = head;
	ListNode *l1 = new ListNode;
	l1->val = 1;
	temp->next = l1;
	temp = temp->next;
	ListNode *l2 = new ListNode;
	l2->val = 2;
	temp->next = l2;
	temp = temp->next;
	ListNode *l3 = new ListNode;
	l3->val = 3;
	temp->next = l3;
	temp = temp->next;
	ListNode *l4 = new ListNode;
	l4->val = 3;
	temp->next = l4;
	temp = temp->next;
	l4->next = NULL;

	ListNode *result;
	Solution s;
	result = s.deleteDuplicates(head);
	while (result != NULL){
		cout << result->val;
		if (result->next != NULL)
			cout << "->";
		result = result->next;
	}
	cout << endl;
	delete head, l1, l2, l3, l4;
	system("pause");
}