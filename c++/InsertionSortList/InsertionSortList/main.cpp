/*
*	Insertion Sort List
*	Last Modified: 7/23/2015
*	Hint:
		Unsorted list: 6->5->3->1->8->7->2->4
		Insert node value int_min
		Steps:
			1) 6->NULL, int_min->6, 5->3->1->8->7->2->4->NULL 
			2) 6->NULL, int_min->5, 5->6, 3->1->8->7->2->4->NULL
			3) 6->NULL, int_min->3, 3->5->6, 1->8->7->2->4->NULL
			4) 6->NULL, int_min->1, 1->3->5->6, 8->7->2->4->NULL
			5) 1->3->5->6->8->NULL, int_min->8, 7->2->4->NULL
			6) 1->3->5->6->7->8->NULL, int_min->7, 2->4->NULL
			7) 1->2->3->5->6->7->8->NULL, int_min->2, 4->NULL
			8) 1->2->3->4->5->6->7->8->NULL, int_min=NULL
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *temp = new ListNode(INT_MIN);	//Insertion node
		//temp->next = head;
		while (head){
			ListNode *curr = head;
			ListNode *prev = temp;
			head = head->next;
			while (prev->next && prev->next->val <= curr->val)
				prev = prev->next;
			curr->next = prev->next;
			prev->next = curr;
		}
		head = temp->next;
		delete temp;
		return head;
	}
};

void main(int argc, char *argv[]){
	ListNode *head = new ListNode(6);
	ListNode *print = head;
	ListNode *tail = head;
	ListNode *n1 = new ListNode(5);
	tail->next = n1;
	tail = tail->next;
	ListNode *n2 = new ListNode(3);
	tail->next = n2;
	tail = tail->next;
	ListNode *n3 = new ListNode(1);
	tail->next = n3;
	tail = tail->next;
	ListNode *n4 = new ListNode(8);
	tail->next = n4;
	tail = tail->next;
	ListNode *n5 = new ListNode(7);
	tail->next = n5;
	tail = tail->next;
	ListNode *n6 = new ListNode(2);
	tail->next = n6;
	tail = tail->next;
	ListNode *n7 = new ListNode(4);
	tail->next = n7;
	tail = tail->next;

	cout << "The unsorted list is: ";
	while (print){
		cout << print->val;
		print = print->next;
		if (print) cout << "->";
	}
	cout << endl;

	Solution s;
	ListNode *sorted = s.insertionSortList(head);
	cout << "The sorted list is: ";
	while (sorted){
		cout << sorted->val;
		sorted = sorted->next;
		if (sorted) cout << "->";
	}
	cout << endl;
	system("pause");
}