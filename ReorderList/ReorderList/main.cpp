/*
*	Reorder List
*	Last Modified: 7/23/2015
*	Hint: 
		1. Break list in the middle to two lists (use fast & slow pointers)
		2. Reverse the order of the second list
		3. Merge two list back together
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
	void reorderList(ListNode* head) {
		if (!head || !head->next) return;

		//1. Break the list into two parts
		ListNode *fast = head;
		ListNode *prevSlow = head;
		ListNode *slow = head;

		while (true){
			prevSlow = slow;
			slow = slow->next;
			if (fast->next) fast = fast->next->next;
			else break;
			if (!fast || !slow) break;
		}
		prevSlow->next = NULL;	//Terminate the first half
		
		//2. Reverse the second half
		ListNode *head2Half = slow;	//Start of the second half
		ListNode *p1 = head2Half;
		ListNode *p2 = head2Half->next;
		head2Half->next = NULL;
		while (p1 && p2){
			ListNode *temp = p2->next;
			p2->next = p1;
			p1 = p2;
			if (temp) p2 = temp;
			else break;
		}

		//3. Merge two lists
		ListNode *newHead1Half = head;	//Make a new head of the 1st half
		ListNode *newHead2Half = p1;	//Make a new head of the reverses 2nd half
		while (newHead2Half){
			ListNode *temp1 = newHead1Half->next;
			ListNode *temp2 = newHead2Half->next;
			newHead1Half->next = newHead2Half;
			newHead2Half->next = temp1;
			newHead1Half = temp1;
			newHead2Half = temp2;
		}
	}
};

void main(int argc, char *argv[]){
	ListNode *head = new ListNode(1);
	ListNode *print = head;
	ListNode *tail = head;
	ListNode *n1 = new ListNode(2);
	tail->next = n1;
	tail = tail->next;
	/*ListNode *n2 = new ListNode(3);
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
	ListNode *n7 = new ListNode(8);
	tail->next = n7;
	tail = tail->next;
	ListNode *n8 = new ListNode(9);
	tail->next = n8;
	tail = tail->next;*/

	cout << "The original list is: ";
	while (print){
		cout << print->val;
		print = print->next;
		if (print) cout << "->";
	}
	cout << endl;

	Solution s;
	s.reorderList(head);
	cout << "The reordered list is: ";
	while (head){
		cout << head->val;
		head = head->next;
		if (head) cout << "->";
	}
	cout << endl;
	system("pause");
}