/*
*	Rotate List
*	Last Modified: 7/21/2015
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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		if (k == 0 ) return head;
		int len = 0;
		ListNode *p = head;
		//First, get the total length of the list
		while (p){
			p = p->next;
			len++;
		}
		k = k%len;
		ListNode *temp = new ListNode(0);
		temp->next = head;		//Attach a temporary node before head node

		ListNode *curr = temp;
		int count = 1;
		while (count <= len - k && curr){
			curr = curr->next;
			count++;
		}

		//cout << curr->val << endl;
		if (curr == temp) return head;		//If k is greater than the length of the list
		ListNode *pivot = curr;		//Record the rotation node


		ListNode *newHead = NULL;
		if (curr->next) newHead = curr->next;		//Record the position of the new head node

		while (curr->next)
			curr = curr->next;	//Traverse to the end of the list

		curr->next = head;	//Connect the tail to the head
		temp->next = pivot->next;
		pivot->next = NULL;		//Make pivot the end of the list
		head = temp->next;	//Change new head node
		delete temp;
		return head;
	}
};

void main(int argc, char* argv[]){
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
	ListNode *n4 = new ListNode(5);
	tail->next = n4;
	tail = tail->next;

	int k = 4;
	Solution s;

	cout << "The original list is: ";
	while (print){
		cout << print->val;
		print = print->next;
		if (print) cout << "->";
	}
	cout << endl;

	ListNode *res = s.rotateRight(head, k);
	cout << "The rotated list is: ";
	while (res){
		cout << res->val;
		res = res->next;
		if (res) cout << "->";
	}
	cout << endl;
	system("pause");
}