/*
*	Partition List
*	Last Modified: 6/18/2015
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
	ListNode* partition(ListNode *head, int x){
		ListNode *p = new ListNode(x - 1);	
		p->next = head;//Inserts a extra node
		head = p;	//Changes the head to the newly inserted node
		ListNode *previous = head;
		//Finds the first element whose value is not less than x
		while (p != NULL && p->val < x){
			previous = p;
			p = p->next;
		}
		//If p doesn't reach the last node of the list
		if (p != NULL){
			ListNode *current = previous;
			while (p != NULL){
				if (p->val < x){
					ListNode *temp = current->next;
					previous->next = p->next;
					current->next = p;
					current = p;
					p->next = temp;
					p = previous;
				}
				previous = p;
				p = p->next;
			}
		}
		ListNode *temp = head;
		head = head->next;
		delete temp;
		return head;
	}
};

void main(int argc, char *argv[]){
	ListNode *head = new ListNode(1);
	ListNode *tail = head;
	ListNode *print = head;
	ListNode *node1 = new ListNode(4);
	tail->next = node1;
	tail = tail->next;
	ListNode *node2 = new ListNode(3);
	tail->next = node2;
	tail = tail->next;
	ListNode *node3 = new ListNode(2);
	tail->next = node3;
	tail = tail->next;
	ListNode *node4 = new ListNode(5);
	tail->next = node4;
	tail = tail->next;
	ListNode *node5 = new ListNode(2);
	tail->next = node5;
	tail = tail->next;

	cout << "The original list is: ";
	while (print != NULL){
		cout << print->val;
		print = print->next;
		if (print != NULL) cout << "->";
	}
	cout << endl;
	Solution s;
	int x = 3;
	ListNode *result = s.partition(head, x);
	cout << "The list after partitioning is: ";
	while (result != NULL){
		cout << result->val;
		result = result->next;
		if (result != NULL) cout << "->";
	} 
	cout << endl;
	system("pause");
}