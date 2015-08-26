/*
*	Swap Nodes In Pairs
*	Last Modified: 6/8/2015
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	ListNode *swapPairs(ListNode *head){
		if (head == NULL)
			return NULL;
		if(head->next == NULL)
			return head;
		if (head->next->next == NULL)
		{
			ListNode *previous = head->next;
			ListNode *current = head;
			ListNode *temp = previous->next;
			previous->next = current;
			current->next = temp;
			return previous;
		}
		else{
			ListNode *returnHead = new ListNode(-1);
			returnHead->next = head;
			ListNode *previous = head->next;	
			ListNode *current = head;
			ListNode *post = returnHead;
			while (previous != NULL)
			{
				ListNode *temp = previous->next;	//Records the next position 
				previous->next = current;	//Moves the front node to the back of the back node
				current->next = temp;	//Changes the pointer to the next
				post->next = previous;
				post = current;
				if (post->next == NULL)
					break;
				current = post->next;
				previous = current->next;
			}
			head = returnHead->next;
			delete returnHead;
			return head;
		}
		
	}
};

void main(int argc, char *argv[]){
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *printList1 = head;
	ListNode *tail = head;
	ListNode *node2 = new ListNode(2);
	tail->next = node2;
	tail = tail->next;
	ListNode *node3 = new ListNode(3);
	tail->next = node3;
	tail = tail->next;
	ListNode *node4 = new ListNode(4);
	tail->next = node4;
	tail = tail->next;
	ListNode *node5 = new ListNode(5);
	tail->next = node5;
	tail = tail->next;

	
	cout << "The original linked list is: ";
	while (printList1 != NULL)
	{
		cout << printList1->val;
		printList1 = printList1->next;
		if (printList1 != NULL)
			cout << "->";
	}
	cout << endl;
	ListNode *resultHead = s.swapPairs(head);
	cout << "The swapped linked list is: ";
	while (resultHead != NULL)
	{
		cout << resultHead->val;
		resultHead = resultHead->next;
		if (resultHead != NULL)
			cout << "->";
	}
	cout << endl;
	system("pause");
}